import { useEffect, useRef } from "react"
import "./Validation.css"

function Validation({message, color="#BF7877", text="#a94442"}) {
    let validation = useRef();
    return (
        <span ref={validation} id="input-error" className="error" aria-live="polite" style={{backgroundColor: color, color: text}}>{message}</span>
    )
}

export default Validation

