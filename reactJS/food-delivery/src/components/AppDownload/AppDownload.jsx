import React from 'react';
import './AppDownload.css';
import { assets } from '../../../assets/assets';

const AppDownload = () => {
    return (
        <div className='app_download' id='app_download'>
            <p>for Better Experience Download <br /> Tomato App</p>
            <div className="app_download_platforms">
                <img src={assets.play_store} alt="playStore" />
                <img src={assets.app_store} alt="appStore" />
            </div>
        </div>
    )
}

export default AppDownload;