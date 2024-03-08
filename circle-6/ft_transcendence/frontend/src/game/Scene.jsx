function Scene() {
    return <>
        <mesh position-y={-0.6} receiveShadow>
            <boxGeometry args={[30, 0.01, 22]} />
            <meshStandardMaterial color={'#888888'} />
        </mesh>
        {/* <mesh position-y={2 / 2 - 0.6} position-z={-11} receiveShadow>
            <boxGeometry args={[30, 2, 0.1]} />
            <meshStandardMaterial color={'#888888'} />
        </mesh>
        <mesh position-y={2 / 2 - 0.6} position-z={11} receiveShadow>
            <boxGeometry args={[30, 2, 0.1]} />
            <meshStandardMaterial color={'#888888'} />
        </mesh>
        <mesh position-y={2 / 2 - 0.6} position-x={-15} receiveShadow>
            <boxGeometry args={[0.1, 2, 22]} />
            <meshStandardMaterial color={'#888888'} />
        </mesh>
        <mesh position-y={2 / 2 - 0.6} position-x={15} receiveShadow>
            <boxGeometry args={[0.1, 2, 22]} />
            <meshStandardMaterial color={'#888888'} />
        </mesh> */}
    </>  
}

export default Scene