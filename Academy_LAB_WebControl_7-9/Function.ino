//------------------------------------------------------------------AGV Control Function -----------------------------------------------------------------------------//
void processAGVMovement(String inputValue) {
  //Serial.printf("Got value as %s %d\n", inputValue.c_str(), inputValue.toInt());
  switch (inputValue.toInt()) {
    case UP:
      forward(10);
      break;
    case DOWN:
      //add function direction
      break;
    case LEFT:
      //add function direction
      break;
    case RIGHT:
      //add function direction
      break;
    case UP_LEFT:
      slide_left_forward(10);
      break;
    case UP_RIGHT:
      slide_right_forward(10);
      break;
    case DOWN_LEFT:
      //add function direction
      break;
    case DOWN_RIGHT:
      //add function direction
      break;
    case TURN_LEFT:
      //add function direction
      break;
    case TURN_RIGHT:
      //add function direction
      break;
    case STOP:
      stop(10);
      break;
    default:
      stop(10);
      break;
  }
}

