import { Link } from "react-router-dom"
import DisplayCard from "../../components/Card/Card"


const  Folder = (props) => {

        
        console.log(props.product);
        const updateHandler = (newname) => {
          props.setName(newname)
        }


        return(
        <div className='code-directories'> 
        {props.product.map((productItem) => (
            <Link to = {props.name+'/'+ productItem.name}>
            <DisplayCard path = {props.name+'/'+ productItem.name}
               name={productItem.name}
                onClick={() => {
                  const newname = props.name+"/" + productItem.name
                  updateHandler(newname)
                  console.log("name:" +  props.name)
                  console.log(props.name+'/'+productItem.name)
                  props.setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + newname + "?ref=master")
                  console.log("url" + props.url)
                }}/>
            </Link>
                ))}
        </div>
  )
}

export default Folder;
