<h1>Stop-Watch-System</h1>
  <h2>Project Description</h2>
  <p>The project is a stop watch system that controls the stop-watch time and displays it on 7-segments.</p>
  <h2>Project Specifications</h2>
    <p>
     <br>Stop Watch counting starts once the power is connected to the MCU.</br>
     <br>An external Interrupt INT0 is configured with a falling edge. A push button is connected with the internal pull-up resistor. If a falling edge is detected, the          Stop Watch time will reset reset.
     </br>
     <br>An external Interrupt INT1 is configured with a raising edge. A push button is connected with the external pull-down resistor. If a raising edge is detected,            the Stop Watch time will be paused.
     </br>
     <br>An external Interrupt INT2 is configured with a falling edge. A push button is connected with the internal pull-up resistor. If a falling is edge detected, the          Stop Watch time will be resumed.
     </br>
    </p>
  <h2>Project Components</h2>
    <h3>Micrcontroller</h3>
      <p>
       <br>- ATmega16</br>
      </p>
    <h3>Drivers</h3>
      <p>
       <br>- GPIO</br>
       <br>- Timres</br>
       <br>- External Interrupts</br>
       <br>- 7-Segment</br>
      </p>
  <h2>Files</h2>
    <p>main.c : This file contains the code of the project.</p>
