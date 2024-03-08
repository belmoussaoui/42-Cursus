import { useEffect, useState } from "react";
import { director } from "../../lib/Director";
import "./Player.css"
import { useTranslation } from "react-i18next";

function Player({player1, player2}) {
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
					{ player1.username }
					</div>
					<div className="player-name">
					{ player2.username}
					</div>
				</div>
				<div className="container-fluid">
					<div className="row">
						<div className="col-md-2">
							<div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (player1.profile_url ? "https://127.0.0.1:8080" + player1.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
						</div>
						<div className="col-md-4 my-auto align-items-center">
							<div className="p-1">
								<div className="player-box">
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_won')}</span>
										<span className="">{ player1.games_won }</span>
									</div>
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_lost')}</span>
										<span className="">{ player1.games_lost }</span>
									</div>

								</div>
							</div>
						</div>
						<div className="col-md-4 my-auto align-items-center">
							<div className="p-1">
								<div className="player-box">
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_won')}</span>
										<span className="">{ player2.games_won }</span>
									</div>
									<div className="p-2 d-flex justify-content-between">
										<span className="">{t('games_lost')}</span>
										<span className="">{ player2.games_lost }</span>
									</div>
								</div>
							</div>
						</div>
						<div className="col-md-2">
							<div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (player2.profile_url ? "https://127.0.0.1:8080" + player2.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
						</div>
					</div>

				</div>
				</div>

        </div>
    )
}

export default Player