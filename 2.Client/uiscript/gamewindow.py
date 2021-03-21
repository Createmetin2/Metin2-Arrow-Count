#Add to end
import app
if app.BL_ARROW_COUNT:
	window["children"] += (
			{ 
				"name":"Arrow_Icon",
				"type":"button",
				"x" : 65,
				"y" : SCREEN_HEIGHT - 170,

				"default_image" : "icon/item/79501.tga",
				"over_image" : "icon/item/79501.tga",
				"down_image" : "icon/item/79501.tga",
				
				"tooltip_text" : "Arrow Count",
				
				"children" :
				(
					{
						"name":"Arrow_Count",
						"type":"text", 
						"x": 20,
						"y": 38, 
						"text":"",
						"fontsize" : "LARGE",
						"r":1.0, "g":1.0, "b":1.0, "a":1.0,
						"text_horizontal_align":"center"
					},
				),
			},
		)