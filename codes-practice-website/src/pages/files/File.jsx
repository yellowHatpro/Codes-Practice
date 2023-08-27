import React, { useState, useEffect } from 'react'
import './File.css'
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

     <pre className="code-block"> {fileContent} </pre>
    
     </div>
  )
}

export default File
