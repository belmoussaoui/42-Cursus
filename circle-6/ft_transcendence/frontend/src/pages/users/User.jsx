import { director } from "../../lib/Director";
import { useTranslation } from "react-i18next";
import { useEffect, useState } from "react";
import "./Users.css";
import { useParams } from "react-router-dom";
import Button from "../../components/button/Button";
import P404 from "../p404/p404";
import Block from "../../components/block/Block";
import Chat from "./Chat";

const Match = ({ username }) => {
    const [userMatches, setUserMatches] = useState([]);

    useEffect(() => {
        let getMatchs = async() => {
            let data = await director("game/user-matches/" + username + "/")
            setUserMatches(data);
        }
        getMatchs();
    }, []);

    if (userMatches.length === 0) return <div className="p-5">No match history</div>

    return (
        <div>
            {userMatches.map(match => (
                <div key={match.id}>
                    <div className="log-item">
                        <div className="log-main">
                            <p className="title">
                                <span className="score">Score : { match.score_player1} -  { match.score_player2}</span>
                            </p>
                            <p className="content">
                                <a href={`${match.player1}`}>{match.player1}</a> vs <a href={match.player2 ? match.player2 : ""}>{ match.player2 ? match.player2 : "anonyme" }</a> on { match.game_mode }
                            </p>
                            <span>{ new Intl.DateTimeFormat('fr-FR', { year: 'numeric', month: 'long', day: 'numeric', hour: '2-digit', minute: '2-digit', second: '2-digit' }).format(new Date(match.date_played)) }</span>
                        </div>
                        <div className="log-middle"></div>
                    </div>
                </div>
            ))}
        </div>
    );
};

function User() {
	const { username } = useParams();
	const [user, setUser] = useState(null);
	const [login, setLogin] = useState({});
	const {t} = useTranslation();
    const [friend, setFriend] = useState({});
    const [friendRequests, setFriendRequests] = useState([]);
    const [friendSends, setFriendSends] = useState([]);
    const [value, setValue] = useState(0);
 
    useEffect(() => {
        let getUser = async() => {
            let login = await director("auth/get_user_from_token")
            setLogin(login);
            let data = await director("auth/get_user/" +  username + "/")
            setUser(data);
            let data2 = await director("auth/are_friends/" +  username + "/")
            setFriend(data2.are_friends);
            if (username == login.username)
                setFriend(true)
        }
        getUser();
        getFriendSends();
        


        getFriendRequests().then((friendRequests) => {
            setFriendRequests(friendRequests);
        });
    }, [])

    async function sendFriendRequest(username) {
        await director(`auth/send_friend_request/${username}/`, 'POST');
        window.location.reload();
    }
    
    async function acceptFriendRequest(username) {
        await director(`auth/accept_friend_request/${username}/`, 'POST');
        let data2 = await director("auth/are_friends/" + username)
        setFriend(data2.are_friends);
    }

    async function getFriendRequests() {
        const friendRequests = await director(`auth/get_friend_request/${username}/`);
        return friendRequests;
    }

    async function getFriendSends() {
        const data = await director(`auth/get_friend_send/${username}/`);
        setFriendSends(data);
    }

    async function deleteFriend() {
        const data = await director(`auth/delete_friend/${username}/`, "POST");
        getFriendRequests().then((friendRequests) => {
            setFriendRequests(friendRequests);
        });
        setFriend(false);
    }

    if (!user || user.detail == "Not found.") return <P404></P404>
    return (
        <>
            <div className="profile">
                <div className="container-fluid">
                <div className="user-header">
                    <div className="player-name">{user ? user.username : null}</div>
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
                                <span className="">{friend ? (user.available ? "Available" : "Unavailable ") : "No Friend :("}</span>
                            </div>
                            <div>
                                { !friend && friendRequests.length == 0  && friendSends.length == 0? 
                                    <Button onClick={() => {sendFriendRequest(username);  getFriendSends();}}>
                                        Send friend request
                                    </Button> : null
                                }
                                {
                                    friend && username != login.username ?
                                    <Button onClick={() => {deleteFriend();}}>
                                        delete friend
                                    </Button> : null
                                }
                            </div>
                            <div>
                            {!friend ? friendRequests.map((request) => (
                                <div key={request.user}>
                                    <p>{request.user} sent you a friend request</p>
                                    <Button onClick={() => acceptFriendRequest(request.user)}>
                                        Accept
                                    </Button>
                                </div>
                            )): null}
                            </div>
                        </div>
                        <div className="col-md-4"></div>
                        <div className="col-md-3">
                            <div className="bg-image-item profile-image rounded user-image" style={{ backgroundImage: "url(" + (user.profile_url ? "https://127.0.0.1:8080" + user.profile_url : "/marvin.png") + ")", margin: "5px"}}></div>
                        </div>
                    </div>
                </div>
            </div>
            <div className="container-fluid">
                <div className="row">
                { friend ? <Block>{user ? <Chat user={user} login={login}></Chat>: null}</Block> : null}
                <Block>
                    <div className="changelogs-list my-3 overflow-auto h-100">
                        <Match username={username}></Match>
                    </div>
                </Block>   
                </div> 
            </div>
        </>
    )
}

export default User