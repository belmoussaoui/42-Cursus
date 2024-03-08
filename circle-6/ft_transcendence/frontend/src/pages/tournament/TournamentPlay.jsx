
import { useTranslation } from 'react-i18next';
import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import Button from "../../components/button/Button";
import Game from '../../game/Game';
import { KeyboardControls } from '@react-three/drei';
import { Canvas } from '@react-three/fiber';
import { director } from '../../lib/Director';
import "./Tournament.css"
import P404 from '../p404/p404';


function TournamentPlay() {
	const { tournamentid } = useParams();
	const [tournament, setTournament] = useState(null);
	const [nextMatch, setNextMatch] = useState({});
	const {t} = useTranslation();


	useEffect(() => {
		const getMatchs = async () => {
			let data = await director(`tournament/${tournamentid}/`);
			if (data?.detail == "Not found.")
				data = null;
			setTournament(data);
			if (!data) return
			let nextMatch = data.matches.find(match => !match.winner && match.player2 && match.player1) || null;
			setNextMatch(nextMatch);
		}
		getMatchs();
	}, [tournamentid]);

	const renderMatches = () => {
		if (!tournament) return null;
		const { matches, rounds } = tournament;
		matches.sort((a, b) => a.id - b.id);
		const renderedMatches = [];
		for (let i = 1; i <= rounds; i++) {
			renderedMatches.push([]);
		}
		let isFoundNextMatch = false;
		matches.forEach(match => {
			const player1 = match.player1 ?  match.player1 : null;
			const player2 = match.player2 ? match.player2 : null;
			const winner = match.winner ? match.winner : null;
			
			let backColor = "#00babc"
			if (!winner) {
				if (!isFoundNextMatch) {
				backColor = "#D8636F"
				isFoundNextMatch = true;
				}
			}

			const player1Name = player1 ? player1 : '?';
			const player2Name = player2 ? player2 : '?';

			const matchDisplay = (
				<div key={match.id} className="match-box p-3 mr-3" style={{'backgroundColor': backColor}}>
					<div className="d-flex w-100 justify-content-around">
					<label className="px-2" style={{color: "white"}}>{player1Name}</label>
					<label className="px-2" style={{color: "white"}}>vs</label>
					<label className="px-2" style={{color: "white"}}>{player2Name}</label>
					</div>
					<div>
					{ winner ? <label className="px-2" style={{color: "white"}}>{winner}</label> : null}
					</div>

				</div>
			);
			renderedMatches[match.round - 1].push(matchDisplay);
		});

		const columns = renderedMatches.map((matches, index) => (
			<div key={index} className="col">
				<div className='h-100 d-flex flex-column justify-content-center'>
				<div className='round'>Round {index + 1}</div>
				{matches}
				</div>
			</div>
		));

		return (
			<div className="container-fluid">
				<div className="row">{columns}</div>
			</div>
			);
	};


	if (!tournament) {
		return <P404></P404>;
	}

	let terminate = (object) => {
		setTimeout(() => {
		let newGame = async (object) => {
			let winner = object.score.player1 > object.score.player2 ? 0 : 1
			await director(`tournament/${tournamentid}/play-next-match`, "POST", { nextMatchId: nextMatch.id, winnerId: winner });
			window.location.reload();
		}
		newGame(object);
		}, 1000);
	}

	return (
		<>
		<div className="row">
			<div className="col-lg-12">
				<div className="settings">
				<div className="container-item">
					<h5 className="title-settings">{tournament.name} Tournament</h5>
					<div className="row">
					<div className="col">
						{renderMatches()}
					</div>
					</div>
		
				</div>
				</div>
			</div>
		</div>
		<div className="d-flex justify-content-center  align-items-center h-100">
				<div>
					{nextMatch && (<KeyboardControls
						map={[
						{ name: "Down01", keys: ['KeyS', 'KeyD'] },
						{ name: "Up01", keys: ['KeyW', 'KeyA'] },
						{ name: "Up02", keys: ['ArrowUp', 'ArrowLeft'] },
						{ name: "Down02", keys: ['ArrowDown', 'ArrowRight'] },
						{ name: "Serve", keys: ['Space'] },
						]}
					>
					<Canvas shadows linear flat camera={{ position: [0, 35, 0], fov: 40 }}>
						<Game points={3} speed={4} terminate={terminate}></Game>
					</Canvas>
					</KeyboardControls>)}

				</div>
			</div>
			
		</>
	);
}

export default TournamentPlay;