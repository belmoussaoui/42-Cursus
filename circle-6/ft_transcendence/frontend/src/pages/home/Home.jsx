import Block from "../../components/block/Block"
import Button from "../../components/button/Button"
import "./Home.css"
import { useEffect, useState } from 'react'
import { Link } from "react-router-dom";
import { useNavigate } from 'react-router-dom';
import { director } from "../../lib/Director";
import Profile from "./Profile";
import { useTranslation } from "react-i18next";


function Home() {
    const [data, setData] = useState("?");
    const [config, setConfig] = useState({ speed: 3, points: 5, ia: 0 });
    const [room, setRoom] = useState("");
    const {t} = useTranslation();
    const [tournaments, setTournaments] = useState([]);
    const [players, setPlayers] = useState(4);
    const [friends, setFriends] = useState([]);

    const handlePlayers = (event) => {
        setPlayers(event.target.value);
    };


    useEffect(() => {
        const tournaments = async () => {
            let data = await director("tournament/all");
            setTournaments(data);
        }
        tournaments();
        let getFriends = async() => {
            let data = await director("auth/get_friends")
            setFriends(data);
        }
        getFriends();
      }, []);


    const navigate = useNavigate();


    const deepthought = async () => {
        let data = await director("deepthought/answer")
        setData(data.answer);
    }

    function playLocalMatch() {
        navigate('/local', {"state": config});
    }

    function createTournament() {
        navigate('/tournament', {"state": {"players": players}});
    }

    function joinRoom() {
        navigate(`/online/${room ? room : "42"}`);
    }
    
    return (
        <>
        <Profile></Profile>
        <div className="container-fluid">
            <div className="row">
                <Block title={t("deep_tought")}>
                    <div className="text-center">
                        <Button href="" onClick={deepthought}>{t("answer")}</Button>
                        <p className="mt-3">{t("answer_of_life")} : {data}</p>
                    </div>
                </Block>

                <Block title={t("play_local")}>
                    <div className="text-center">
                    <div className="d-flex justify-content-between align-items-center">
                            <label className="">{t("ia")}</label>
                            <div>
                                <input onChange={e =>  setConfig(prevState => ({...prevState, ["ia"]:  parseInt(e.target.value)}))} min="0" max="4" defaultValue="0" className="config-number" type="number"></input>
                            </div>
                        </div>
                        <div className="d-flex justify-content-between align-items-center">
                            <label className="">{t("points")}</label>
                            <div>
                                <input onChange={e =>  setConfig(prevState => ({...prevState, ["points"]:  parseInt(e.target.value)}))} min="3" max="39" defaultValue="5" className="config-number" type="number"></input>
                            </div>
                        </div>
                        <div className="d-flex justify-content-between align-items-center">
                            <label className="">{t("game_speed")}</label>
                            <div>
                                <input onChange={e =>  setConfig(prevState => ({...prevState, ["speed"]: parseInt(e.target.value)}))} min="1" max="5" defaultValue="3" className="config-number" type="number"></input>
                            </div>
                        </div>
                        <Button onClick={playLocalMatch}>
                            {t("play")}
                        </Button>
                    </div>
                </Block>

                <Block title={t("tournament")}>
                    <div className="text-center">
                        <div className="list-group overflow">
                                {tournaments.map(tournament => (
                                    !tournament.finished ?
                                <Link
                                    to={`/tournament/${tournament.id}`}
                                    className="event-item"
                                    key={tournament.id}
                                >
                                    <div className="d-flex w-100 justify-content-between">
                                        <h5 className="tournament-name">{tournament.name}</h5>
                                    </div>
                                    <div className="event-bottom d-flex align-content-center flex-wrap">
                                        <div className="event-location">
                                            <span className="icon-location"></span>
                                            <span className="mt-3">{tournament.players.length}</span>
                                        </div>
                                    </div>
                                </Link> : null
                                ))}
                        </div>
                        {/* <label className="">{t('tournament_players')}</label> */}
                        <div className="p-2">
                            <select className="form-control" type="text" value={players} onChange={handlePlayers}>
                                <option value="2">2 players</option>
                                <option value="4">4 players</option>
                                <option value="8">8 players</option>
                                <option value="16">16 players</option>
                            </select>
                        </div>
                        <Button onClick={createTournament}>
                            {t("tournament")}
                        </Button>
                    </div>
                </Block>

                <Block title={t("play_multiplayer")}>
                    <div className="text-center">
                        <div className="d-flex justify-content-between align-items-center">
                            <label className="">{t("game_room")}</label>
                            <div>
                                <input maxLength="30" onChange={e =>  setRoom(e.target.value.replace(/[^\w-]/g, ''))} className="config-input" type="text"></input>
                            </div>
                        </div>
                        <div className="py-3">
                            <Button className="mx-2" onClick={joinRoom}>
                                {t("join")}
                            </Button>
                        </div>
                    </div>
                </Block>

                <Block title={t("friends")}>
                    <div className="text-center overflow-auto" style={{height: "200px"}}>
                        <div className="container-friend">
                            {friends.map(user => (
                                <div key={user.id} className="item-friend m-3 border-black border">
                                    <h6 className="name-firend">{user.username}</h6>
                                    <div className="d-flex justify-content-evenly">
                                        <span>{user.available ? "Available" : "Unavailable"}</span>
                                        <span><Link to={`/user/${user.username}`}>See profile</Link></span>

                                    </div>
                                </div>
            
                            ))} 
                        </div>
                    </div>
                </Block>
                
            </div>
        </div>
    </>
    )
}

export default Home