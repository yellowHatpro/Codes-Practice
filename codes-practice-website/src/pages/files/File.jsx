import React, { useState, useEffect } from 'react'
import './File.css'
import {CopyBlock, solarizedLight} from "react-code-blocks";
const File = ({url}) => {
    const [fileContent, setFileContent] = useState("")
    useEffect(() => {
        fetch(url)
            .then(res => res.text())
            .then(content => {
                setFileContent(content)
            })
    }, [])

    return (
        <div className="code-container">
            {
                (fileContent) ? <pre
                    className="code-block">
           <CopyBlock
               language={"cpp"}
               text={fileContent}
               showLineNumbers={true}
               theme={solarizedLight}
               wrapLines={true}
               codeBlock
           />
       </pre> : "Loading"
            }

        </div>
    )
}

export default File
