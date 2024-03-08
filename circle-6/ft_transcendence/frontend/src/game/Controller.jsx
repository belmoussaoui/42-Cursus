import { useKeyboardControls } from "@react-three/drei"
import { useFrame } from "@react-three/fiber"


function Controller({socket, type}) {  
    const [ subscribeKeys, getKeys ] = useKeyboardControls()
    useFrame((state, delta) => {
		const { Up01, Down01, Up02, Down02, Serve } = getKeys()
        Up01 && (socket.current.send(JSON.stringify({
            event: 'MOVE',
            type: type,
            direction : 1,
            playerId: 1,
        })))
        Down01 && (socket.current.send(JSON.stringify({
            event: 'MOVE',
            type: type,
            direction : -1,
            playerId: 1,
        })))
        Up02 && (socket.current.send(JSON.stringify({
            event: 'MOVE',
            type: type,
            direction : 1,
            playerId: 2,
        })))
        Down02 && (socket.current.send(JSON.stringify({
            event: 'MOVE',
            type: type,
            direction : -1,
            playerId: 2,
        })))
        Serve && (socket.current.send(JSON.stringify({
            type: type,
            event: 'START',
        })))
    })

    return <></>
}

export default Controller;