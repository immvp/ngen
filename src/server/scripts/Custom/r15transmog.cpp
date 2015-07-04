class r15transmog : public PlayerScript
{
public:
	r15transmog() : PlayerScript("r15transmog") { }

	class Transmog : public BasicEvent
	{
	public:
		Transmog(Player* player) : player(player) {}

		bool Execute(uint64 /*time*/, uint32 /*diff*/)
		{
			for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
			{
				player->SetVisibleItemSlot(i, player->GetItemByPos(i));
			}
			return true;
		}
		Player* player;
	};

	void OnLogin(Player* player)
	{
		if (player->GetTotalTokens(player) >= 1480)
		{
			player->m_Events.AddEvent(new Transmog(player), player->m_Events.CalculateTime(5000));
		}
	}
};

void AddSC_r15transmog()
{
	new r15transmog();
}