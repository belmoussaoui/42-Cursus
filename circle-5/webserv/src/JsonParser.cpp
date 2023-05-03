#include "JsonParser.hpp"

JsonParser::JsonParser(char *configFile) {
	std::ifstream infile(configFile);
	if (!infile.is_open())
		throw std::runtime_error("Unable to open file");
	std::ostringstream oss;
	oss << infile.rdbuf(); // read file contents into stringstream
	std::string str = oss.str();
	infile.close();
	parseJsonString(str);
}

JsonParser::~JsonParser() {

}

std::vector<json_value> JsonParser::getJsonVector() const {
	return _json_object_vector;
}

int JsonParser::parseJsonString(std::string &str) {
	if (str.empty() || str[0] != '[')
		throw std::runtime_error("Expected '['");
	str.erase(0, 1);  // consume the '['
	while (!str.empty() && str[0] != '}') {
		_json_object_vector.push_back(parse_object(str));
		if (str[0] == ']') {
			str.erase(0, 1);  // consume the ']'
			break;
		}
		if (str.empty() || str[0] != ',')
			throw std::runtime_error("Expected ','");
		str.erase(0, 1);  // consume the ','
	}
	return 0;
}

// Helper function to trim whitespace from a string
std::string JsonParser::trim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");
	if (start == std::string::npos || end == std::string::npos) {
		return "";
	}
	return str.substr(start, end - start + 1);
}

// Parse a JSON object from a string
// This function assumes that the string starts with a JSON object
// and consumes the characters corresponding to the object
// Returns the parsed object
// Throws an exception if the string is not a valid JSON object
json_value JsonParser::parse_object(std::string& str) {
	str = trim(str);
	json_value j_object;
	j_object.type = object;
	str.erase(0, 1);  // consume the '{'
	while (!str.empty() && str[0] != '}') {
		// Parse a key-value pair
		std::string key = parse_value(str).string_value;
		if (str.empty() || str[0] != ':')
			throw std::runtime_error("Expected ':'");
		str.erase(0, 1);  // consume the ':'
		j_object.object_value[key] = parse_value(str);
		if (!str.empty() && str[0] == ',') {
			str.erase(0, 1);  // consume the ','
		}
		str = trim(str);
	}
	if (str.empty() || str[0] != '}')
		throw std::runtime_error("Expected '}'");
	str.erase(0, 1);  // consume the '}'
	str = trim(str);
	return j_object;
}


// Parse a JSON array from a string
// This function assumes that the string starts with a JSON array
// and consumes the characters corresponding to the array
// Returns the parsed array
// Throws an exception if the string is not a valid JSON array
json_value JsonParser::parse_array(std::string& str) {
	json_value j_array;
	j_array.type = array;
	str.erase(0, 1);  // consume the '['
	while (!str.empty() && str[0] != ']') {
		j_array.array_value.push_back(parse_value(str));
		if (!str.empty() && str[0] == ',') {
			str.erase(0, 1);  // consume the ','
		}
	}
	if (str.empty() || str[0] != ']')
		throw std::runtime_error("Expected ']'");
	str.erase(0, 1);  // consume the ']'
	return j_array;
}

// Parse a JSON value from a string
// This function assumes that the string starts with a JSON value
// and consumes the characters corresponding to the value
// Returns the parsed value
// Throws an exception if the string is not a valid JSON value
json_value JsonParser::parse_value(std::string& str) {
	str = trim(str);
	json_value value;
	if (str.empty())
		throw std::runtime_error("Unexpected end of string");
	switch (str[0]) {
		case '{': {
			value = parse_object(str);
			break;
		}
		case '[': {
			value = parse_array(str);
			break;
		}
		case '"': {
			// Parse a string
			value.type = string;
			size_t end_quote = str.find_first_of('"', 1);
			if (end_quote == std::string::npos) {
				throw std::runtime_error("Unterminated string");
			}
			value.string_value = str.substr(1, end_quote - 1);
			str.erase(0, end_quote + 1);  // consume the string and the trailing quote
			break;
		}
		case 't': {
			// Parse true
			if (str.substr(0, 4) != "true") {
				throw std::runtime_error("Expected 'true'");
			}
			str.erase(0, 4);  // consume 'true'
			value.type = boolean;
			value.boolean_value = true;
			break;
		}
		case 'f': {
			// Parse false
			if (str.substr(0, 5) != "false") {
				throw std::runtime_error("Expected 'false'");
			}
			str.erase(0, 5);  // consume 'false'
			value.type = boolean;
			value.boolean_value = false;
			break;
		}
		case 'n': {
			// Parse null
			if (str.substr(0, 4) != "null") {
				throw std::runtime_error("Expected 'null'");
			}
			str.erase(0, 4);
			value.type = null;
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '-': {
			// Parse an integer
			value.type = integer;
			size_t end_number = str.find_first_not_of("-0123456789");
			if (end_number == std::string::npos) {
				end_number = str.size();
			}
			std::string number_str = str.substr(0, end_number);
			if (number_str.empty() || (number_str.size() > 1 && number_str[0] == '0')) {
				throw std::runtime_error("Invalid number");
			}
			bool negative = false;
			size_t number_start = 0;
			if (number_str[0] == '-') {
				negative = true;
				number_start = 1;
			}
			int number = 0;
			for (size_t i = number_start; i < number_str.size(); i++) {
				number = number * 10 + (number_str[i] - '0');
			}
			if (negative) {
				number = -number;
			}
			value.number_value = number;
			str.erase(0, end_number);
			break;
		}
		default :
		{
			std::cerr << "Unexpected character: " << str[0] << std::endl;
			throw std::runtime_error("Unexpected character");
			break;
		}
	}
	return value;
}

std::ostream &operator<<(std::ostream &os, const json_value obj) {
	switch (obj.type) {
		case null:
			os << "null";
			break;
		case boolean:
			os << (obj.boolean_value ? "true" : "false");
			break;
		case integer:
			os << obj.number_value;
			break;
		case string:
			os << '"' << obj.string_value << '"';
			break;
		case array: {
			os << '[';
			bool first = true;
			for (std::vector<json_value>::const_iterator ite = obj.array_value.begin(); ite != obj.array_value.end(); ite++) {
				if (!first) {
					os << ", ";
				}
				first = false;
				os << *ite;
			}
			os << ']';
			break;
		}
		case object: {
			os << '{';
			bool first = true;
			for (std::map<std::string, json_value>::const_iterator it = obj.object_value.begin(); it != obj.object_value.end(); it++) {
				if (!first) {
					os << ", ";
				}
				first = false;
				os << '"' << it->first << "\": " << it->second;
			}
			os << '}';
			break;
		}
	}
	return os;
}
