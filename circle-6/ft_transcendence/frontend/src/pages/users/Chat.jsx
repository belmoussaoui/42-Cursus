import { useCallback, useEffect, useRef, useState } from "react";
import { Link } from "react-router-dom";
import Button from "../../components/button/Button";
import { director } from "../../lib/Director";

function Chat({user, login}) {
	const [message, setMessage] = useState('');
	const handleMessage = (event) => {
        setMessage(event.target.value);
    };
	const [messages, setMessages] = useState([]);

	let socket = useRef(null);
	const chatRef = useRef(null);

	const scrollToBottom = () => {
		if (chatRef.current) {
		  chatRef.current.scrollTop = chatRef.current.scrollHeight;
		}
	};

	let sendMessage = (e) => {
		e.preventDefault();
		socket.current.send(JSON.stringify({"message": message, "sender": login.username, "code": null}));
		setMessage("");
		scrollToBottom();
	}

	let inviteMatch = (e) => {
		e.preventDefault();
		let code = Math.floor(100000 + Math.random() * 900000)
		socket.current.send(JSON.stringify({"message": `room code = ${code}`, "sender": login.username, "code": code}));
	}

	useEffect(() => {
		scrollToBottom();

	}, [messages]);
	useEffect(() => {
		let getMessages = async() => {
            let messages = await director("livechat/messages/" + user.username + "/")
            setMessages(messages);
        }
        getMessages();
		
		let token = localStorage.getItem('token');
		socket.current = new WebSocket(`wss://127.0.0.1:8080/ws/livechat/${user.username}/?token=${token}`);
		
		socket.current.onopen = () => {
		};
	
		socket.current.onmessage = (e) => {
			let object = JSON.parse(e.data);
			setMessages((prevMessages) => [...prevMessages, object]);
		};
	  }, []);

	return  <div className="container">
			<div className="row">
			<div className="col-12">
				<div className="card">
					<div ref={chatRef} style={{height: "200px", overflowY: "auto"}} className="p-2">
						<div className="messages">
							{messages.map(msg => {
								return (
									!msg.code ?
									<div key={msg.id}>{msg.sender}: {msg.message}</div> :
									<div key={msg.id} >
									<Link to={`/online/${msg.code}`}>{msg.sender}: {msg.code}</Link>
									</div>
								)
							})}
						</div>
					</div>
					<form onSubmit={(e) => { sendMessage(e); }}>
					<div className="card-footer">
						<input id="text"
								type="text"
								placeholder="Your message"
								className="form-control"
								onChange={handleMessage}
								value={message}
								maxLength="254"
								autoComplete="off"
								required
						/>
						<div className="my-3">
							<Button className="save" type="submit">Send</Button>
							<Button onClick={inviteMatch} type="submit">Invite Match</Button>
						</div>
					</div>
					</form>
					</div>
				</div>
			</div>
		</div>
}

export default Chat;