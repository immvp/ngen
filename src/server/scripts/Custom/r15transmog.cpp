class r15transmog : public PlayerScript
{
public:
	r15transmog() : PlayerScript("r15transmog") { }

	void OnLogin(Player* player)
	{
		if (player->HasTitle(72))
		{
			for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
			{
				player->SetVisibleItemSlot(i, player->GetItemByPos(i));
			}
		}
	}
};

void AddSC_r15transmog()
{
	new r15transmog();
}