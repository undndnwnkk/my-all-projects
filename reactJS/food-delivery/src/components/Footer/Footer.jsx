import React from 'react';
import './Footer.css';
import { assets } from '../../../assets/assets';

const Footer = () => {
    return (
        <div className='footer' id='footer'>
            <div className="footer_content">
                <div className="footer_content_left">
                    <img src={assets.logo} alt="footer" />
                    <p>Lorem ipsum dolor sit amet consectetur, adipisicing elit. Exercitationem fugit repudiandae reprehenderit animi temporibus optio mollitia dolor nesciunt! Saepe deserunt quaerat autem et est laudantium id iusto ut, a distinctio?</p>
                    <div className="footer_social_icons">
                        <img src={assets.facebook_icon} alt="facebook" />
                        <img src={assets.twitter_icon} alt="twitter" />
                        <img src={assets.linkedin_icon} alt="linkedin" />
                    </div>
                </div>
                <div className="footer_content_right">
                    <h2>COMPANY</h2>
                    <ul>
                        <li>Home</li>
                        <li>About us</li>
                        <li>Delivery</li>
                        <li>Privacy policy</li>
                    </ul>
                </div>
                <div className="footer_content_center">
                    <h2>GET IN TOUCH</h2>
                    <ul>
                        <li>+1-234-567-8901</li>
                        <li>contact@tomato.com</li>
                    </ul>
                </div>
            </div>
            <hr />
            <p className="footer_copyright">
                Copyright 2024 © Tomato.com - All Right Reserved.
            </p>
        </div>
    )
}

export default Footer;