#!/bin/bash
cat ../sql/updates/world/3.3.5/*.sql > world_update.sql
cat ../sql/custom/world/*.sql > world_update_custom.sql
cat ../sql/custom/characters/*.sql > characters_update_custom.sql
cat ../sql/custom/auth/*.sql > auth_update_custom.sql