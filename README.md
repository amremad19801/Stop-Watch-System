<h1>Stop-Watch-System</h1>
  <p>The project is a stop watch system that controls the stop-watch time and displays it on 7-segments.</p>
  <h2>Project Description</h2>
    <p><br>Stop Watch counting starts once the power is connected to the MCU.</br>
    <br>An external Interrupt INT0 is configured with falling edge. A push button is connected with the internal pull-up resistor. If a falling edge is detected, the             Stop Watch time will reset reset.
    </br>
    <br>An external Interrupt INT1 is configured with raising edge. A push button is connected with the external pull-down resistor. If a raising edge is detected, the           Stop Watch time will be paused.
    </br>
    <br>An external Interrupt INT2 is configured with falling edge. A push button is connected with the internal pull-up resistor. If a falling is edge detected, the             Stop Watch time will be resumed.
    </br>
    </p>
  <h2>Project Components</h2>
    <h3>Drivers</h3>
      <p>GPIO</p>
      <p>Timres</p>
      <p>External Interrupts</p>
      <p>7-Segment</p>
    <h3>Micrcontroler</h3>
      <p>ATmega16</p>
  <h2>Files</h2>
    <p>main.c : This file contains the code of the project.</p>
