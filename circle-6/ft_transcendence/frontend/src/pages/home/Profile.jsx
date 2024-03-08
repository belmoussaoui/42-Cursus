import { useEffect, useState } from "react";
import { director } from "../../lib/Director";
import "./Profile.css"
import { useTranslation } from "react-i18next";

function Profile() {
    const [user, setUser] = useState({});
	const {t} = useTranslation();

    useEffect(() => {
        let getUser = async() => {
            let data = await director("auth/get_user_from_token")
            setUser(data);
        }
        getUser();
    }, [])

    return (
        <div className="profile">
            <div className="container-fluid">
            <div className="user-header">
            </div>
                <div className="row">
                    <div className="col-md-4 user-box ">
                        <div className="p-2 d-flex justify-content-between">
                            <span className="">{t('games_won')}</span>
                            <span className="">{user ? user.games_won : 0}</span>
                        </div>
                        <div className="p-2 d-flex justify-content-between">
                            <span className="">{t('games_lost')}</span>
                            <span className="">{user ? user.games_lost : 0}</span>
                        </div>
                        <div className="p-2 d-flex justify-content-between">
                            <span className="">{user.available ? "Available" : "Unavailable "}</span>
                        </div>
                    </div>
                    <div className="col-md-4"></div>
                    <div className="col-md-3">
                        <div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (user.profile_url ? "https://127.0.0.1:8080" + user.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
                    </div>
                </div>
            </div>

        </div>
    )
}

export default Profile