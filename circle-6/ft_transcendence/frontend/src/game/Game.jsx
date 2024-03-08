import Ball from './Ball';
import Scene from './Scene';
import Paddle from './Paddle';
import { useEffect, useRef, useState } from 'react';
import Controller from './Controller';
import Score from './Score';
import { useThree } from '@react-three/fiber';
import { OrbitControls } from '@react-three/drei';

function Game({ speed, points, ia, terminate, online = false, room = "", newChallenger = null, newRole = null, type = "spectate" }) {
  const paddleRef1 = useRef();
  const paddleRef2 = useRef();
  const ballRef = useRef();
  const { camera, size, setDefaultCamera } = useThree();
  let [score1, setScore1] = useState(0);
  let [score2, setScore2] = useState(0);
  let isTerminate = false;

  let onTerminate = (object) => {
    if (!isTerminate) {
        terminate(object);
        isTerminate = true;
    }
  }

  let onUpdate = (object) => {
    if (!ballRef.current || !object.paddles) return
    paddleRef1.current.position.z = -object.paddles.player1;
    paddleRef2.current.position.z = -object.paddles.player2;
    ballRef.current.position.x = object.ball.x;
    ballRef.current.position.z = -object.ball.y;
    if (score1 != object.score.player1 || score2 != object.score.player2) {
      setScore1(object.score.player1);
      setScore2(object.score.player2);
    }
  }

  let updateGame = (object) => {
    if (object.state == "join") {
      newRole(object)
    }
    else if (object.state == "terminate")
      onTerminate(object)
    else
      onUpdate(object)
  }
  const socket = useRef(null);

  useEffect(() => {
    if (!online) {
      let token = localStorage.getItem('token');
      socket.current = new WebSocket(`wss://127.0.0.1:8080/ws/game/?token=${token}`);
    } else {
      let token = localStorage.getItem('token');
      socket.current = new WebSocket(`wss://127.0.0.1:8080/ws/online/?token=${token}`);
    }

	document.addEventListener('touchstart', handleTouchMove);
	document.addEventListener('touchmove', handleServe);
	const handleKeyDown = (event) => {
    if (event.key == 'ArrowDown' || event.key == 'ArrowUp')
		  event.preventDefault();
	};
  
	document.addEventListener('keydown', handleKeyDown);

   

    socket.current.onopen = () => {
      if (!online) {
        socket.current.send(JSON.stringify({
          event: 'CONFIG',
          speed: speed || 4,
          points: points || 7,
          ia: ia || 0,
        }))
      }
      if (online) {
        socket.current.send(JSON.stringify({
          event: 'JOIN',
          room: room
        }))
      }
    };

    socket.current.onmessage = (e) => {
      let object = JSON.parse(e.data);
      updateGame(object);
    };
    return () => {
      socket.current.close();
      document.removeEventListener('keydown', handleKeyDown);
    }
  }, []);

  useEffect(() => {
    if (size.width < 600) {
      camera.position.set(-25, 50, 0);
	  camera.lookAt(0, 0, 0);

    }
    camera.updateProjectionMatrix();
  }, [size.width, camera]);

  const handleServe = () => {
	socket.current.send(JSON.stringify({
		event: 'START',
	}))
  }
  const handleTouchMove = (event) => {
    const touches = event.touches;
	  const canvasHeight = size.height;
   
    if (touches.length >= 1) {
      const touch1Y = -((touches[0].clientY -size.top) / canvasHeight) * 2 + 1;
		if (touch1Y > 1 || touch1Y < -1) return
		const touch1X = ((touches[0].clientX -size.left) / size.width) * 2 - 1;
		if (touch1X > 1 || touch1X < -1) return
    
		if (touch1Y > 0) {
		  for (let i = 0; i < 8; i++) {
			socket.current.send(JSON.stringify({
				  event: 'MOVE',
				  type: type,
				  direction : touch1X < 0 ? 1 : -1,
				  playerId: 2,
		  }))
			
		  }
		} else {
		    for (let i = 0; i < 8; i++) {
				socket.current.send(JSON.stringify({
					  event: 'MOVE',
					  type: type,
					  direction : touch1X < 0 ? 1 : -1,
					  playerId: 1,
			}))
		}
		}
	  }
  };


  return (
	  <>
	  	<OrbitControls></OrbitControls>
		<directionalLight shadow-camera-left={-50} shadow-camera-right={30} shadow-camera-top={30} shadow-camera-bottom={-30} color={"#FFFFFF"} castShadow position={[20, 5, 15]} intensity={2} />
		<directionalLight shadow-camera-left={-50} shadow-camera-right={30} shadow-camera-top={30} shadow-camera-bottom={-30} color={"#FFFFFF"} castShadow position={[-10, 20, 15]} intensity={1} />
		<ambientLight intensity={1.8}></ambientLight>
		<Scene></Scene>
		<Score score={[score1, score2]}></Score>
		<Controller type={type} socket={socket}></Controller>
		<Ball ref={ballRef}></Ball>
		<Paddle ref={paddleRef1} position={[-14, 0, 0]}></Paddle>
		<Paddle ref={paddleRef2} position={[14, 0, 0]}></Paddle>
	  </>
    )
}

export default Game