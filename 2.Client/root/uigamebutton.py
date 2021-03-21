#Find
			self.gameButtonDict["EXIT_OBSERVER"].SetEvent(ui.__mem_func__(self.__OnClickExitObserver))
			
#Add
			if app.BL_ARROW_COUNT:
				self.ArrowIcon = self.GetChild("Arrow_Icon")
				self.ArrowCount = self.GetChild("Arrow_Count")
				
#Find
		self.gameButtonDict={}
		
#Add
		if app.BL_ARROW_COUNT:
			self.ArrowIcon = None
			self.ArrowCount = None
			
#Find
	def HideBuildButton(self):
		self.gameButtonDict["BUILD"].Hide()
	
#Add
	if app.BL_ARROW_COUNT:
		def CheckArrowCount(self):
			(count, max) = player.GetArrowStatus()
			if count == -1:
				self.ArrowIcon.Hide()
				return

			if count == -2:
				self.ArrowCount.SetText("Unlimited")
			else:
				self.ArrowCount.SetText("{}/{}".format(count, max))
			self.ArrowIcon.Show()
				
		def OnUpdate(self):
			self.CheckArrowCount()