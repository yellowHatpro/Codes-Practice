import { createStore } from "redux";

const initialState = {
  url : 'https://api.github.com/repos/yellowHatpro/Codes-Practice/contents?ref=master',
  name : ''
}

const reducer = (state = initialState, action) => {
  switch (action.type) {
    case 'UPDATE_URL': return {...state, url: action.payload};
    case 'UPDATE_NAME' : return {...state, name: action.payload};
    default : return state;
  }
}

const store = createStore(reducer)

export default store
