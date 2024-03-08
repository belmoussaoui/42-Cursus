import { useEffect, useState } from "react";
import { director } from "../../lib/Director";
import "./Player.css"
import { useTranslation } from "react-i18next";

function Player() {
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
        <div className="player">
            <div className="container-fluid">
			<div className="player-header">
					<div className="player-name">
					{ user.username }
					</div>
					<div className="player-name">vs</div>
					<div className="player-name">
					marvin
					</div>
				</div>
				<div className="container-fluid">
					<div className="row">
						<div className="col-md-2">
							<div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (user.profile_url ? "https://127.0.0.1:8080" + user.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
						</div>
						<div className="col-md-4 my-auto align-items-center">
							<div className="p-1">
								<div className="player-box">
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_won')}</span>
										<span className="">{user ? user.games_won : 0}</span>
									</div>
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_lost')}</span>
										<span className="">{user ? user.games_lost : 0}</span>
									</div>

								</div>
							</div>
						</div>
						<div className="col-md-4 my-auto align-items-center">
							<div className="p-1">
								<div className="player-box">
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_won')}</span>
										<span className="">{42}</span>
									</div>
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_lost')}</span>
										<span className="">{0}</span>
									</div>
								</div>
							</div>
						</div>
						<div className="col-md-2">
							<div className="bg-image-item player-image rounded" style={{backgroundImage: "url(/marvin.png)"}}></div>
						</div>
					</div>

				</div>
			</div>

        </div>
    )
}

export default Player