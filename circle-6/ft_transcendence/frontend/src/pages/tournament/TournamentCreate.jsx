import React, { useState, useEffect } from 'react';
import { useTranslation } from 'react-i18next';
import Button from '../../components/button/Button';
import { useNavigate, useLocation } from 'react-router-dom';
import { director } from '../../lib/Director';

function TournamentCreate() {
  const { state } = useLocation();
  let np = state?.players || 4;
  const navigate = useNavigate();
  
  const [numberOfPlayers, setNumberOfPlayers] = useState(np);
  const [tournamentName, setTournamentName] = useState("");
  const {t} = useTranslation();

  const [playerNames, setPlayerNames] = useState([]);

  useEffect(() => {
    setPlayerNames(Array(numberOfPlayers).fill(""));
  }, [numberOfPlayers]);

  const [errorMessage, setErrorMessage] = useState('');
  const [message, setMessage] = useState('');

  const handlePlayerNameChange = (index, newName) => {
    const updatedPlayers = [...playerNames];
    updatedPlayers[index] = newName;
    setPlayerNames(updatedPlayers);
  };

  const checkNames= (names) => {
    const uniques = new Set(names.filter(name => name.trim() !== ''));
    const namestrim = names.filter(name => name.trim() !== '');
    if (uniques.size !== namestrim.length) {
      setErrorMessage('Duplicate player names are not allowed.');
      return false;
    } else {
      const hasNonEmptyNames = namestrim.every(name => name !== "");
      if (!hasNonEmptyNames || names.length != namestrim.length) {
        setErrorMessage('Some players names are empty');
        return false;
      }
      setErrorMessage('');
      return true;
    }
  };

  const handleStartTournament = async (e) => {
    e.preventDefault()
    if (!checkNames(playerNames)) return;
    let data = await director("tournament/create_tournament", "POST", {
      name: tournamentName,
      numberOfPlayers: numberOfPlayers,
      playerNames: playerNames.filter(name => name.trim() !== '')
    })
    navigate(`/tournament/${data.tournament_id}`);
  }



  return (
        <div className="container-fluid">
        <div className="row">
          <div className="col-lg-12">
            <div className="settings">
              <div className="container-item">
              <h5 className="title-settings">{t('tournament_setup')}</h5>
              <div className="col-xs-12 col-lg-4">
              <form onSubmit={handleStartTournament}>
                { message ? <Validation message={message} color={"lightgreen"} text={"darkgreen"}></Validation> : null }
                <div className="user_username">
                  <label>{t('tournament_name')}</label>
                  <input
                    maxLength="15"
                    required
                    className="form-control"
                    type="text"
                    value={tournamentName}
                    onChange={(e) => setTournamentName(e.target.value)}
                  />
                </div>
                <div className="profile_username">
                  <label>{t('username')} : </label>
                </div>
                <div>
                    {Array.from({ length: numberOfPlayers }).map((_, index) => (
                  <input
                    maxLength="12"
                    required
                    className="form-control my-2"
                    key={index}
                    type="text"
                    placeholder={`Player ${index + 1}`}
                    value={playerNames[index] || ''}
                    onChange={(e) => handlePlayerNameChange(index, e.target.value)}
                  />
                ))}
                {errorMessage && <p className="text-danger">{errorMessage}</p>}
                </div>
             
                <div className="my-3">
                  <Button className="save" type="submit">{t('save')}</Button>
                </div>
              </form>
              </div>

              </div>

              </div>
            </div>
        </div>
      </div>
  );
}

export default TournamentCreate;
