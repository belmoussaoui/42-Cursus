import i18next from "i18next";
import Button from "../../components/button/Button"
import { director } from "../../lib/Director";
import "./Settings.css"
import { useTranslation } from "react-i18next";
import { useEffect, useState } from "react";
import Validation from "../../components/validation/Validation";



function Settings() {
	const [message, setMessage] = useState('');

	const [image, setImage] = useState(null);

	const [user, setUser] = useState({});

	const handleFileChange = (e) => {
        const file = e.target.files[0];
		if (file) {
			if (file.type === 'image/jpeg' || file.type === 'image/png' || file.type === 'image/gif') {
				setImage(file);
			}
		}
    };

    useEffect(() => {
        let getUser = async() => {
            let data = await director("auth/get_user_from_token")
            setUser(data);
        }
        getUser();
    }, [])
	
	const saveSettings = async (e) => {
		e.preventDefault();
		const formData = new FormData();
        formData.append('profile', image);
		formData.append('language', language);
		formData.append('email', email);
		setMessage("");

        let data = await director("auth/update_user", "POST", formData, true)
		let user = await director("auth/get_user_from_token")
		setMessage("The settings have been updated.");
        i18next.changeLanguage(data.language);
		setUser(user);
    }

	const [language, setLanguage] = useState('');
	const [email, setEmail] = useState('');

	useEffect(() => {
		const token = localStorage.getItem('token');
		fetch('https://127.0.0.1:8080/auth/get_user_from_token', {
			method: 'GET',
			headers: {
				'Content-Type': 'application/json',
				'Authorization': `Token ${token}`
			},
			})
			.then(response => response.json())
			.then((d) => {setLanguage(d.language); setEmail(d.email)});
	  }, [])

    const handleLanguage = (event) => {
        setLanguage(event.target.value);
    };

	const handleEmail = (event) => {
        setEmail(event.target.value);
    };

	const {t} = useTranslation();

    return (
        <>
			<div className="container-fluid">
				<div className="row">
					<div className="col-lg-12">
						<div className="settings">
							<div className="container-item">
							<h5 className="title-settings">{t('settings')}</h5>
							<div className="col-xs-12 col-lg-4">
							<form onSubmit={saveSettings}>
								{ message ? <Validation message={message} color={"lightgreen"} text={"darkgreen"}></Validation> : null }
								<div className="user_username">
									<label className="">{t('username')}</label>
									<div>
										<input className="form-control" disabled="disabled" type="text" defaultValue={user ? user.username : null}/>
									</div>
								</div>
								<div className="profile_username">
									<label className="">{t('profile')}</label>
									<div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (user.profile_url ? "https://127.0.0.1:8080" + user.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
									<input type="file" accept="image/png, image/gif, image/jpeg" onChange={handleFileChange} />
								</div>
								<div className="user_email">
									<label className="">{t('email')}</label>
									<div>
										<input maxLength="255" className="form-control" type="email" defaultValue={user ? user.email : null} onChange={handleEmail}/>
									</div>
								</div>
								<div className="user_language">
									<label className="">{t('language')}</label>
									<div>
										<select className="form-control" type="text" value={language} onChange={handleLanguage}>
											<option value="en">English</option>
  											<option value="fr">Français</option>
  											<option value="es">Español</option>
										</select>
									</div>
								</div>
								<div className="my-3">
									<Button className="save" type="submit">{t('save')}</Button>
								</div>
							</form>
							</div>

							</div>

							</div>
						</div>
				</div>
			</div>
        </>
    )
}

export default Settings