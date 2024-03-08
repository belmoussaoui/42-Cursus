import "./Page.css"
import Navbar from '../components/navbar/Navbar';

function Page({children}) {
    return (
        <main className="page">
            <Navbar></Navbar>
            { children }
        </main>
    )
}

export default Page