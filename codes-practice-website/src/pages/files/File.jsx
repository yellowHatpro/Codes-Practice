import React from 'react'
import './File.css'
import {CopyBlock, solarizedLight} from "react-code-blocks";
import {useQuery} from "@tanstack/react-query";
import {Loading} from "../../components/Loading.jsx";

const File = ({url}) => {
    const {data: fileContent, error, isLoading, isFetching} = useQuery({
        queryKey: ["fileContent"],
        queryFn: async () => {
            return await fetch(url).then(res => res.text())
        }
    })

    if (isLoading) return <Loading/>
    else if (isFetching) return "fetching"
    else if (error) return "Error"
    else if (fileContent) return (
        <pre className="code-block">
           <CopyBlock
               language={"cpp"}
               text={fileContent}
               showLineNumbers={true}
               theme={solarizedLight}
               wrapLines={true}
               codeBlock
           />
       </pre>
    )
}

export default File
