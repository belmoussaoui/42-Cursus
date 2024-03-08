import React, { useEffect, useState } from 'react';
import "./Login.css"
import { useNavigate } from 'react-router-dom';
import Validation from '../../components/validation/Validation';

const Login = () => {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [error, setError] = useState('');
    const navigate = useNavigate();


    useEffect(() => {
        const verifyToken = async () => {
            const token = localStorage.getItem('token');
            if (token) {
                const response = await fetch('https://127.0.0.1:8080/auth/verify_token', {
                    method: 'GET',
                    headers: {
                    'Authorization': `Token ${token}`,
                    },
                });
                if (response.ok) {
                    navigate('/');
                } else {
                    localStorage.removeItem('token');
                }
            }
        }
        verifyToken();
    });


    const handleLogin = async (e) => {
        e.preventDefault();
        const response = await fetch('https://127.0.0.1:8080/auth/login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                username: username,
                password: password,
            }),
        });

        if (response.ok) {
            const data = await response.json();
            localStorage.setItem('token', data.token);
            navigate('/');
        } else {
            setError("");
            const errorMessage = await response.json();
            setError(errorMessage.detail);
        }

    };

    return (
        <div className='login-page'>
            <form className='login-form' onSubmit={handleLogin}>
                { error ? <Validation message={error}></Validation> : null }
                <input
                    maxLength="15"
                    required
                    className='login-input'
                    type="text"
                    placeholder="Login"
                    value={username}
                    onChange={(e) => setUsername(e.target.value)}
                    autoComplete='username'
                />
                <input
                    maxLength="30"
                    required
                    className='login-input'
                    type="password"
                    placeholder="Password"
                    value={password}
                    onChange={(e) => setPassword(e.target.value)}
                    autoComplete='current-password'
                />
                <button type="submit" className='login-button'>Login</button>
                <a className="login-register" href="./register">Not registered yet?</a>
            </form>
        </div>
    );
};

export default Login;