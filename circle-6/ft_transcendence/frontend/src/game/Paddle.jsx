import { forwardRef } from "react";


const Paddle = forwardRef(function Paddle(props, ref) {
    return (
        <mesh
            castShadow
            ref={ref}
            {...props}
        >
            <boxGeometry args={[1, 1, 3]} />
            <meshStandardMaterial color={'white'} />
        </mesh>
    )
})

export default Paddle;
