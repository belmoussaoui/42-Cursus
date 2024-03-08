import { director } from "../../lib/Director";
import { useTranslation } from "react-i18next";
import { useEffect, useState } from "react";
import "./Users.css"



function Users() {

	const [users, setUsers] = useState([]);

    useEffect(() => {
        let getUsers = async() => {
            let data = await director("auth/get_users")
            setUsers(data);
        }
        getUsers();
    }, [])
	


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
			.then((d) => {});
	  }, [])

   

	const {t} = useTranslation();

    return (
        <>
			<div className="container-fluid">
				<div className="row">
					<div className="col-lg-12">
						<div className="settings">
							<div className="container-item">
								<h5 className="title-settings">{t('users')}</h5>
								<div className="col-xs-12 col-lg-4">
							</div>
							{
								users.map(user => (
									<a key={user.id} className="user-item "style={{ backgroundImage: "url(" + (user.profile_url ? "https://127.0.0.1:8080" + user.profile_url : "/marvin.png") + ")", margin: "5px"}} href={"/user/" + user.username}>
										<div className="user-item-container">
											<h4 className="user-item-title">
												{ user.username }
											</h4>
										</div>
									</a>
       							))
							}
							
							</div>

							</div>
						</div>
				</div>
			</div>
        </>
    )
}

export default Users