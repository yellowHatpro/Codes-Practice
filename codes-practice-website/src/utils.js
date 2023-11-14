export const gh_url = "https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/?ref=master"

const handlePath = (setPath) => {
    setPath((oldPath) => {
        const newPath = [...oldPath]
        newPath.pop()
        return newPath
    })
}

const handleUrl = (path, setUrl) => {
    const newPath = [...path]
    newPath.pop()
    const newStr = newPath.join('/')
    setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + newStr + "?ref=master")
}

const handleBackPress = (path, setPath, setUrl) => {
    handlePath(setPath)
    handleUrl(path, setUrl)
}

export {handleBackPress}
