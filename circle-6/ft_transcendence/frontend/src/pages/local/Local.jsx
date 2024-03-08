import { useLocation } from "react-router-dom";
import Game from "../../game/Game.jsx"
import "./Local.css"
import { useNavigate } from "react-router-dom";
import Player from "./Player.jsx";
import { useEffect, useState } from "react";
import { director } from "../../lib/Director.js";
import { Canvas } from "@react-three/fiber";
import { KeyboardControls } from "@react-three/drei";


function Play() {
    const { state } = useLocation();
    const navigate = useNavigate();
    let terminate = () => {
        setTimeout(() => {
			navigate("/");
		}, 1000);
    }

    return (
        <>
            <Player></Player>
            <div className="d-flex justify-content-center align-items-center">
                <div>
                <KeyboardControls
                    map={[
                    { name: "Down01", keys: ['KeyS', 'KeyD'] },
                    { name: "Up01", keys: ['KeyW', 'KeyA'] },
                    { name: "Up02", keys: ['ArrowUp', 'ArrowLeft'] },
                    { name: "Down02", keys: ['ArrowDown', 'ArrowRight'] },
                    { name: "Serve", keys: ['Space'] },
                    ]}
                >
                <Canvas shadows linear flat camera={{ position: [0, 35, 0], fov: 40 }}>
                    <Game ia={state?.ia} points={state?.points} speed={state?.speed} terminate={terminate}></Game>
                </Canvas>
                </KeyboardControls>
                </div>
            </div>
        </>
    )
}

export default Play