#ifndef __Orz_List__
#define __Orz_List__
#include <boost/multi_array.hpp>
#include <iostream>
#include <CEGUI/cegui.h>

#include "WheelAnimalControllerConfig.h"
#include "Number.h"

#include "WinData.h"
namespace Orz
{
	
	
	
	class ListItem
	{

	public:
		ListItem(CEGUI::Window * all, 
			CEGUI::Window * main, 
			CEGUI::Window * banker, 
			CEGUI::Window * king,
			CEGUI::Window * theDouble,
			CEGUI::Window * table
			);
		~ListItem(void);
		void hide(void);
		void show(const WinDataClone & data);
		bool isVisible(void) const;
		const WinDataClone & getData(void) const;
	private:
		CEGUI::Window * _all;
		CEGUI::Window * _main;
		CEGUI::Window * _banker;
		CEGUI::Window * _king;
		CEGUI::Window * _double;
		CEGUI::Window * _table;
		std::map<std::pair<WheelEnum::TYPE, WheelEnum::LIGHT_COLOR>, std::string> _picture;
		WinDataClone _winData;
		bool _visible;
	};
	class List
	{
	public:
		List(void);
		~List(void);
		void show(void);
		void hide(void);
		void add(void);
	private:
		typedef std::vector<ListItem>  ListType;
		ListType _list;
	};
}


#endif