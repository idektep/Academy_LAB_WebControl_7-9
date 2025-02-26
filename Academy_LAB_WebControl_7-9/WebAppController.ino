const char* htmlHomePage PROGMEM = R"HTMLHOMEPAGE(
<!DOCTYPE html>
<html>
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <style>
    .arrows {
      font-size:20px;
      color:Blue;
    }
    .button-container {
      display: flex;
      /* flex-wrap: wrap; */
      justify-content: center;
      align-items: center;
      margin: 10px;
    }
    .button-bg{
      background-color: none;
      color: white;
      border-radius: 45%;
      padding: 30px;
      margin: 3px;
      box-shadow: 3px 5px #888888;
      cursor: pointer;
      font-size: 20px;
      transition: transform 0.1s, box-shadow 0.1s;
    }
    .button {
      background-color: white;
      color: white;
      border-radius: 45%;
      padding: 30px;
      margin: 3px;
      box-shadow: 3px 5px #888888;
      cursor: pointer;
      font-size: 20px;
      transition: transform 0.1s, box-shadow 0.1s;
    }
    .button:active {
      transform: translate(5px, 5px);
      box-shadow: none;
    }
    .noselect {
      -webkit-touch-callout: none; /* iOS Safari */
        -webkit-user-select: none; /* Safari */
         -khtml-user-select: none; /* Konqueror HTML */
           -moz-user-select: none; /* Firefox */
            -ms-user-select: none; /* Internet Explorer/Edge */
                user-select: none; /* Non-prefixed version, currently
                                      supported by Chrome and Opera */
    }
    </style>
  </head>
  <body class="noselect" align="center" style="background-color:#b9fef8;"> 
    <!-- กำหนดปุ่มให้จัดเรียงในแนวนอนโดยใช้ flexbox -->
    <div class="button-container">
      <div class="button" ontouchstart='onTouchStartAndEnd("5")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("1")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("6")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
    </div>   
   <div class="button-container">    
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div style="background-color:none;box-shadow:none"><h3 style="color: #4053e3;text-align:center;">&#128663; Control</h3></div>     
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
   </div>
   <div class="button-container">
    <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button" ontouchstart='onTouchStartAndEnd("__")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#128663;</span></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>
      <div class="button-bg" style="background-color:none;box-shadow:none"></div>  
   </div>

    <script>
      var webSocketUrl = "ws:\/\/" + window.location.hostname + "/ws";
      var websocket;
      
      function initWebSocket() 
      {
        websocket = new WebSocket(webSocketUrl);
        websocket.onopen    = function(event){}; // เมื่อเชื่อมต่อ WebSocket สำเร็จ
        websocket.onclose   = function(event){setTimeout(initWebSocket, 2000);}; // ถ้าตัดการเชื่อมต่อ เชื่อมต่อใหม่ทุก 2 วินาที
        websocket.onmessage = function(event){}; // หากมีข้อความที่ได้รับจาก WebSocket
      }

      function onTouchStartAndEnd(value) 
      {
        websocket.send(value);  // ส่งค่าที่ได้รับจากการสัมผัสปุ่มไปยัง WebSocket
      }
          
      window.onload = initWebSocket;
      document.getElementById("mainTable").addEventListener("touchend", function(event){
        event.preventDefault()
      });      
    </script>

    <script>
      function toggleCheckbox(x) {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/" + x, true);
        xhr.send();
      }, 1000);
    </script>
  </body>
</html>  

)HTMLHOMEPAGE";

void handleRoot(AsyncWebServerRequest *request)
{
  request->send_P(200, "text/html", htmlHomePage);
}

void handleNotFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "File Not Found");
}

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    // client->text(getRelayPinsStatusJson(ALL_RELAY_PINS_INDEX));
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    processAGVMovement("0");
    break;
  case WS_EVT_DATA:
    AwsFrameInfo *info;
    info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
    {
      std::string myData = "";
      myData.assign((char *)data, len);
      processAGVMovement(myData.c_str());
      Serial.println(myData.c_str());
    }
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  default:
    break;
  }
}
