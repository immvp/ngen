class TimedGobjectSpawn : public GameObjectScript
{
public:
        TimedGobjectSpawn() : GameObjectScript("TimedGobjectSpawn") { }
 
        void OnLootStateChanged(GameObject* go, uint32 /*state*/, Unit* /*unit*/)
        {
                if (go->getLootState() == GO_JUST_DEACTIVATED)
                {
                        time(&currentTime);
                        localTime = localtime(&currentTime);
                        int m = localTime->tm_min;
                        int s = localTime->tm_sec;
                        int respawnSeconds = ((60 - m) * 60) - s;
                        std::cout << std::endl << "Respawn in " << respawnSeconds << " seconds!" << std::endl;
                        go->SetRespawnTime(respawnSeconds);
                }
        }
 
private:
        time_t currentTime;
        struct tm *localTime;
};
 
void AddSC_TimedGobjectSpawn()
{
        new TimedGobjectSpawn();
}
