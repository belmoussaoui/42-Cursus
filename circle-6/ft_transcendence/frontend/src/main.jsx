import React from 'react'
import ReactDOM from 'react-dom/client'
import { createBrowserRouter, RouterProvider,} from "react-router-dom";
import Home from './pages/home/Home.jsx';
import Local from './pages/local/Local.jsx';
import "./main.css"
import "bootstrap/dist/css/bootstrap.min.css"
import Register from './pages/register/Register.jsx';
import Login from './pages/login/Login.jsx';
import PrivateRoute from './lib/PrivateRoute.jsx';
import Online from './pages/online/Online.jsx';
import i18n from 'i18next';
import { I18nextProvider, initReactI18next } from 'react-i18next';
import en from '/locales/en.json';
import fr from '/locales/fr.json';
import es from '/locales/es.json';
import i18next from 'i18next';
import Settings from './pages/settings/Settings.jsx';
import Users from './pages/users/Users.jsx';
import User from './pages/users/User.jsx';
import P404 from './pages/p404/p404.jsx';
import TournamentCreate from './pages/tournament/TournamentCreate.jsx';
import TournamentPlay from './pages/tournament/TournamentPlay.jsx';


const router = createBrowserRouter([
  {
    path: "/",
    element: <PrivateRoute component={Home} />,
  },
  {
    path: "/local/",
    element: <PrivateRoute component={Local} />,
  },
  {
    path: "/tournament/:tournamentid",
    element: <PrivateRoute component={TournamentPlay} />,
  },
  {
    path: "/tournament/",
    element: <PrivateRoute component={TournamentCreate} />,
  },
  {
    path: "/register/",
    element: <Register />,
  },
  {
    path: "/login/",
    element: <Login />,
  },
  {
    path: "/settings/",
    element: <PrivateRoute component={Settings} />,
  },
  {
    path: "/online/:roomName",
    element: <PrivateRoute component={Online} />,
  },
  {
    path: "/users",
    element: <PrivateRoute component={Users} />,
  },
  {
    path: "/user/:username",
    element: <PrivateRoute component={User} />,
  },
  {
    path: "*",
    element: <PrivateRoute component={P404} />,
  },
]);

i18n
  .use(initReactI18next)
  .init({
    resources: {
      en: {
        translation: en,
      },
      fr: {
        translation: fr,
      },
      es: {
        translation: es,
      },
    },
    lng: 'en',
    fallbackLng: 'fr',
    interpolation: {
      escapeValue: false,
    },
  });


ReactDOM.createRoot(document.getElementById('root')).render(
  // <React.StrictMode>
  <I18nextProvider i18n={i18next}>
    <RouterProvider router={router} />
  </I18nextProvider>
  // </React.StrictMode>,
)
