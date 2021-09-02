#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include "includes/railcats_settings.h"

extern "C++" {RailCats_Settings RailCatsSettings;}

#include "includes/railcats_connector_p50.h"

extern "C++" {RailCats_Connector_p50 dccConnector;}

#include "includes/railcats_logic_objects.h"
extern "C++" {RailCats_Locomotive MyLoco;}
extern "C++" {RailCats_LocoCollection MyLocoCollection;}


#include "includes/railcats_service.h"
extern "C++" {RailCats_Service RailCatsService;}

#include "includes/railcats_queue.h"

extern "C++" {RailCats_Queue MainQueue;}
extern "C++" {RailCats_Queue ExecQueue;}


#endif // GLOBALSETTINGS_H
