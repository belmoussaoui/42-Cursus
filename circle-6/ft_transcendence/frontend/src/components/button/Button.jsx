import "./Button.css"

const Button = ({ children, ...props }) => {
  return (
    <button variant={'primary'} {...props} className="button-main mx-4">
      {children}
    </button>
  );
};

export default Button;