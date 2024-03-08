import { useEffect, useState } from 'react';
import "./Navbar.css"
import { useNavigate } from 'react-router-dom';
import {useTranslation} from "react-i18next";


function Navbar() {
  const navigate = useNavigate();
  const [user, setUser] = useState({});
  const {t} = useTranslation();
  
  useEffect(() => {
    const token = localStorage.getItem('token');
    fetch('https://127.0.0.1:8080/auth/get_user_from_token', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json',
            'Authorization': `Token ${token}`,
        },
        })
        .then(response => response.json())
        .then((d) => setUser(d));
  }, [])

  const handleLogout = () => {
    const token = localStorage.getItem('token');
    fetch('https://127.0.0.1:8080/auth/logout', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json',
            'Authorization': `Token ${token}`
        },
    })
    localStorage.removeItem('token');
    navigate('/login');
  };

  return (
    <nav className="navbar-main">
      <div><span className='px-3' data-login="bel-mous"> {user ? user.username : null}</span></div>
      <div className='px-1'>
        <button className="btn btn-secondary mx-2" onClick={() => { navigate('/settings');}}>
          <span>{t('settings')}</span>
        </button>
        <button className="btn btn-danger" onClick={handleLogout}>
          <span>{t('logout')}</span>
        </button>
      </div>
    </nav>
  );
}

export default Navbar;
