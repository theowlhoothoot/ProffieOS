
class MenuDial : public PropBase, SaberBase {
public:
	MenuDial() : PropBase() {}
	MenuDial() : SaberBase() {}

	void MenuDialLoop() {

#ifdef ENABLE_SCROLL_MENU //START OF SCROLL MENU LOOP FUNCTION FOR SWITCH CASE. THIS TRIGGERST HE BASE FUNCTIONS DELCARED OUTSIDE FOR MENU FUCNTIONS.

#define TICK_ANGLE_2 (M_PI * 2 / 12)
		switch (scroll_menu_enabled) {
		case true: {
			SaberBase::RequestMotion();
			uint32_t t = millis();
			activated_ = millis();
			switch (
				
				_mode) {
			case FONT_CHANGE:
			{
				float a = fusor.angle2() - current_tick_angle_;
				if (a > M_PI) a -= M_PI * 2;
				if (a < -M_PI) a += M_PI * 2;
				if (a > TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ += TICK_ANGLE_2;
					if (current_tick_angle_ > M_PI) current_tick_angle_ -= M_PI * 2;
					STDOUT << "TICK+\n";
					if (!track_player_) {
						previous_preset();
					}
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				if (a < -TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ -= TICK_ANGLE_2;
					if (current_tick_angle_ < M_PI) current_tick_angle_ += M_PI * 2;
					STDOUT << "TICK-\n";
					if (!track_player_) {
						next_preset();
					}
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				break;
			}
			case SOUND_CHANGE:
			{
				float a = fusor.angle2() - current_tick_angle_;
				if (a > M_PI) a -= M_PI * 2;
				if (a < -M_PI) a += M_PI * 2;
				if (a > TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ += TICK_ANGLE_2;
					if (current_tick_angle_ > M_PI) current_tick_angle_ -= M_PI * 2;
					STDOUT << "TICK+\n";
					if (!track_player_) {
						previous_menu_voice();
					}
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				if (a < -TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ -= TICK_ANGLE_2;
					if (current_tick_angle_ < M_PI) current_tick_angle_ += M_PI * 2;
					STDOUT << "TICK-\n";
					if (!track_player_) {
						next_menu_voice();
					}
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				break;
			}
			case MAIN_MENU:
			{
				float a = fusor.angle2() - current_tick_angle_;
				if (a > M_PI) a -= M_PI * 2;
				if (a < -M_PI) a += M_PI * 2;
				if (a > TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ += TICK_ANGLE_2;
					if (current_tick_angle_ > M_PI) current_tick_angle_ -= M_PI * 2;
					STDOUT << "TICK+\n";
					//If a track is playing wait for it to finish.
					if (!track_player_) {
						previous_menu();
					}
					//If a track is playing, reset the angles so we dont fuck things up.
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				if (a < -TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ -= TICK_ANGLE_2;
					if (current_tick_angle_ < M_PI) current_tick_angle_ += M_PI * 2;
					STDOUT << "TICK-\n";
					if (!track_player_) {
						next_menu();
					}
					//If a track is playing, reset the angles so we dont fuck things up.
					else {
						start_tick_angle_ = fusor.angle2();
						current_tick_angle_ = fusor.angle2();
					}
				}
				break;
			}
			case VOLUME_CHANGE:
			{
				float a = fusor.angle2() - current_tick_angle_;
				if (a > M_PI) a -= M_PI * 2;
				if (a < -M_PI) a += M_PI * 2;
				if (a > TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ += TICK_ANGLE_2;
					if (current_tick_angle_ > M_PI) current_tick_angle_ -= M_PI * 2;
					STDOUT << "TICK+\n";
					decrease_volume();
				}
				if (a < -TICK_ANGLE_2 * scrollfactor) {
					current_tick_angle_ -= TICK_ANGLE_2;
					if (current_tick_angle_ < M_PI) current_tick_angle_ += M_PI * 2;
					STDOUT << "TICK-\n";
					increase_volume();
				}
				break;
			}
			case BATTERY_CHECK:
			{
				check_battery();
			}

			}
		}
		}
#endif // ENABLE_SCROLL_MENU
	}
}