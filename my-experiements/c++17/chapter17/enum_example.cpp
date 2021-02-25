#include <iostream>

enum class cmd_id_t : int {
  CMD_STATUS = 0,
  CMD_STOP
};

#if 0
enum class cmd_simple_id_t : public cmd_id_t {
  CMD_ECHO = CMD_STOP + 1
};

int main() {

  for (int id = cmd_id_t.CMD_STATUS, 
      id <=  cmd_simple_id_t::CMD_ECHO; id++)
  {
    cmd_simple_id = static_cast<cmd_dimple_id_t>(id) ;
    switch(cmd_simple_id) {
      case CMD_STATUS:
        std::cout << "CMD_STATUS" << std::endl;
        break;
      case CMD_STOP:
        std::cout << "CMD_STOP" << std::endl;
        break;
      case CMD_ECHO:
        std::cout << "CMD_ECHO" << std::endl;
        break;
      default:
        std::cout << "Unkown command" << std::endl;
    }
  }
  return 0;
}
#endif
