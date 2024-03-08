import "./Block.css"

function Block({title, children}) {
    return <div className="col-lg-4 col-md-6 col-xs-12">
        <div className="block-inner">
        <h4 className="block-title">
            {title}
        </h4>
        
        <div>
            {children}
        </div>
        
        </div>
    </div>
}

export default Block