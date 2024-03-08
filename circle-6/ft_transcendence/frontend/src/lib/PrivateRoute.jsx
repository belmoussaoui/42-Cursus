import { useState, useEffect } from 'react';
import { Navigate } from 'react-router-dom';
import Sidebar from '../components/navbar/Sidebar';
import Page from '../pages/Page';
import i18next from 'i18next';

const PrivateRoute = ({ component: Component, ...rest }) => {
    const [isAuthenticated, setIsAuthenticated] = useState(null);
    const [token, setToken] = useState(null);
    
    useEffect(() => {
        const verifyToken = async () => {
            const token = localStorage.getItem('token');
            if (token) {
                setToken(token);
                const response = await fetch('https://127.0.0.1:8080/auth/verify_token', {
                    method: 'GET',
                    headers: {
                        'Authorization': `Token ${token}`,
                    },
                });
                if (response.ok) {
                    const responseData = await response.json();
                    i18next.changeLanguage(responseData.language);
                    setIsAuthenticated(true);
                } else {
                    setIsAuthenticated(false);
                    localStorage.removeItem('token');
                }
            } else
                setIsAuthenticated(false);
        };

        verifyToken();
    }, [token]);
    if (localStorage.getItem('token') != token)
        setToken(localStorage.getItem('token'));
    if (isAuthenticated === null) {
        return <div>Loading...</div>;
    } else if (isAuthenticated) {
        return  <>
            <Sidebar></Sidebar>
            <Page>
                <Component {...rest} />
            </Page>
        </>
    } else {
        return  <Navigate to="/login" replace />;
    }
};

export default PrivateRoute;