import { forwardRef } from "react";


const Ball = forwardRef(function Ball(props, ref) {
    return (
        <mesh
            castShadow
            ref={ref}
            {...props}
        >
            <boxGeometry args={[1, 1, 1]} />
            <meshStandardMaterial color={'white'} />
        </mesh>
    )
})

export default Ball