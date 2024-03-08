import { useFrame } from "@react-three/fiber"
import { useRef } from "react"
import { Group } from "three"


function D01({color}) {
	return <>
		<mesh position={[0, 0, 0]} rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[1.6, 0.4]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D02({color}) {
	return <>
		<mesh position={[-1.1, 0, 0.8]} rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[0.4, 1.6]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D03({color}) {
	return <>
		<mesh position={[1.1, 0, 0.8]}rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[0.4, 1.6]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D04({color}) {
	return <>
		<mesh position={[0, 0, 1.65]}rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[1.6, 0.4]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D05({color}) {
	return <>
		<mesh position={[-1.1, 0, 2.5]}rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[0.4, 1.6]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D06({color}) {
	return <>
		<mesh position={[1.1, 0, 2.5]}rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[0.4, 1.6]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}

function D07({color}) {
	return <>
		<mesh position={[0, 0, 3.3]}rotation={[-Math.PI / 2, 0, 0]}>
			<planeGeometry args={[1.6, 0.4]}></planeGeometry>
			<meshStandardMaterial color={color} />
		</mesh>
	</>
}


let table = [
	[0, 1, 2, 4, 5, 6],
	[2, 5],
	[0, 2, 3, 4, 6],
	[0, 2, 3, 5, 6],
	[1, 2, 3, 5],
	[0, 1, 3, 5, 6],
	[0, 1, 3, 4, 5, 6],
	[0, 2, 5],
	[0, 1, 2, 3, 4, 5, 6],
	[0, 1, 2, 3, 5, 6],
]
function Digit({digit, position=[0, 0, 0]}) {
	digit = Math.floor(digit);

	let led = table[digit];

	return <group position={position} scale={[0.9, 0.9, 0.9]}>
		<D01 color={led.includes(0) ?'white': "#989898"}/>
		<D02 color={led.includes(1) ?'white': "#989898"}/>
		<D03 color={led.includes(2) ?'white': "#989898"}/>
		<D04 color={led.includes(3) ?'white': "#989898"}/>
		<D05 color={led.includes(4) ?'white': "#989898"}/>
		<D06 color={led.includes(5) ?'white': "#989898"}/>
		<D07 color={led.includes(6) ?'white': "#989898"}/>
	</group>
}


let oldScore = [0, 0];
function Score({score}) {
	let scoreRef1 = useRef();
	let scoreRef2 = useRef();
	let anim1 = 0;
	let anim2 = 0;
	useFrame((state, delta) => {
		if (oldScore[0] != score[0]) {
			anim1 = 120;
			oldScore = score;
		}
		if (anim1 > 110)
			scoreRef1.current.visible = false;
		else if (anim1 > 80)
			scoreRef1.current.visible = true;
		else if (anim1 > 70)
			scoreRef1.current.visible = false;
		else if (anim1 > 40)
			scoreRef1.current.visible = true;
		else if (anim1 > 30)
			scoreRef1.current.visible = true;
		else
			scoreRef1.current.visible = true;
		anim1--;
		if (oldScore[1] != score[1]) {
			anim2 = 120;
			oldScore = score;
		}
		if (anim2 > 110)
			scoreRef2.current.visible = false;
		else if (anim2 > 80)
			scoreRef2.current.visible = true;
		else if (anim2 > 70)
			scoreRef2.current.visible = false;
		else if (anim2 > 40)
			scoreRef2.current.visible = true;
		else if (anim2 > 30)
			scoreRef2.current.visible = true;
		else
			scoreRef2.current.visible = true;
		anim2--;
	});
    return <>
		<group ref={scoreRef1}>
			<Digit position={[-4.5, -.5, -10]} digit={score[0] / 10}/>
			<Digit digit={score[0] % 10}  position={[-1.8, -.5, -10]}/>
		</group>
		<group ref={scoreRef2}>
			<Digit digit={score[1] / 10}  position={[1.8, -.5, -10]}/>
			<Digit digit={score[1] % 10}  position={[4.5, -.5, -10]}/>
		</group>

		
    </>  
}

export default Score