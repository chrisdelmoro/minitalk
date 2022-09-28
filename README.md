<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/minitalk/blob/main/resources/repo/minitalkm.png" alt="Logo" width="150" height="150">

  <p align="center">
    The purpose of this project is to code a small data exchange program using UNIX signals.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Bonus-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-110-blue"/>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

In this project the student has to find a way to code a message delivery system using only UNIX signals. To be more precise, only use of the SIGUSR1 and SIGUSR2 signals is allowed. The only way to achieve this, is to break down every byte of the message into its composing bits and send these two signals to represent each and every bit of the message. The student then has to code a client program and a server program. The client will take the server PID and message string as parameters, break the message into individual bits and send SIGUSR1 and SIGUSR2 to the server to represent these bits. The server will receive these signals, interpret them as either 0 or 1 and them encode every byte of the string again to print the original message on screen.

This project has two possible bonuses: Coding unicode support and coding the server to send a signal back to the client that the message was received. I coded that later option.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Use ```make``` to compile the mandatory part of the project and ```make bonus``` to compile the bonus.
In both cases, run the server binary located in its respective /bin folder first. It will printf it own PID. Copy the server PID as the first parameter when running the client binary. After that, simply type the message you wish to send to the server as the second parameter between double quotes. i.e.: ```./client 4527 "The quick brown fox jumps over the lazy dog."```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html). 

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmor@gmail.com

Project Link: [https://github.com/chrisdelmoro/minitalk](https://github.com/chrisdelmoro/minitalk)

<p align="right">(<a href="#top">back to top</a>)</p>
