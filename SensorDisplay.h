#ifndef SENSORDISPLAY_H
#define SENSORDISPLAY_H

#include "DisplayElement.h"
#include "Visualization.h"
#include "SensorData.h"
#include "Stats.h"

class SensorDisplay : public DisplayElement {

	public:
		int enabled     = 0;
		int needsRedraw = 0;
		SensorData *data;   /** reference to externally owned data */
		Visualization *viz; /** GRAPH | DIAL | ONOFF set by menu control, but owned by this class*/
		Stats stats;        /** block of numerical outputs */

		SensorDisplay();
		SensorDisplay(SensorData *dataSource);

		virtual ~SensorDisplay();

		virtual SensorDisplay& operator= (SensorDisplay *param);

		virtual int operator== (const SensorDisplay *param);

		virtual void setTFT(Adafruit_ILI9340 *tft);

		/** deletes old viz it points to, assumes ownership of new viz being passed to it */
		virtual void setViz(Visualization *viz);

		virtual void draw();

		virtual void redraw();

		/** the calling code is responsible for calling redraw after calling this function */
//		virtual void locate(int x, int y);

		/** the calling code is responsible for calling redraw after calling this function */
	    virtual void locateAndSize(int centerX, int centerY, int w, int h);

	    virtual void reset();

};
#endif
