import { useLocation } from "react-router-dom";
import Game from "../../game/Game.jsx"
import { useNavigate } from "react-router-dom";
import Player from "./Player.jsx";
import { useParams } from 'react-router-dom';
import { useState } from "react";
import { KeyboardControls } from "@react-three/drei";
import { Canvas } from "@react-three/fiber";

function Online() {
    const { state } = useLocation();
    let [player1, setPlayer1] = useState("");
	let [player2, setPlayer2] = useState("");
    let [type, setType] = useState("spectate");
    const navigate = useNavigate();
    let terminate = () => {
        setTimeout(() => {
			navigate("/");
		}, 1000);
    }
    
    const { roomName } = useParams();

    const newRole = (object) => {
        setType((prevType) => {
            if (prevType !== "player1") {
                return object.role;
            }
            return prevType;
        });
		newChallenger(object.player1, object.player2);
	};

    const newChallenger = (user1, user2) => {
        setPlayer1(user1);
        setPlayer2(user2);
	};


    return (
        <>
            <Player player1={player1} player2={player2}></Player>
            <div className="d-flex justify-content-center align-items-center h-100">
                <div>
                    {(<KeyboardControls
                        map={[
                        { name: "Down01", keys: ['KeyS', 'KeyD'] },
                        { name: "Up01", keys: ['KeyW', 'KeyA'] },
                        { name: "Up02", keys: ['ArrowUp', 'ArrowLeft'] },
                        { name: "Down02", keys: ['ArrowDown', 'ArrowRight'] },
                        { name: "Serve", keys: ['Space'] },
                        ]}
                    >
                    <Canvas shadows linear flat camera={{ position: [0, 35, 0], fov: 40 }}>
                        <Game type={type} newRole={newRole} newChallenger={newChallenger} online={true} room={roomName} points={state?.points} speed={state?.speed} terminate={terminate}></Game>
                        </Canvas>
                    </KeyboardControls>)}
                </div>
            </div>
        </>
    )
}

export default Online