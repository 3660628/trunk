//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef CC_BOUNDING_BOX_EDITOR_DLG_HEADER
#define CC_BOUNDING_BOX_EDITOR_DLG_HEADER

#include <ui_boundingBoxEditorDlg.h>

//qCC_db
#include <ccBBox.h>

//! Dialog to define the extents of a 3D box
class ccBoundingBoxEditorDlg : public QDialog, public Ui::BoundingBoxEditorDialog
{
	Q_OBJECT

public:

    //! Default constructor
    ccBoundingBoxEditorDlg(QWidget* parent=0);

    //! Returns bounding box
	ccBBox getBox() const { return m_currentBBox; }

    //! Sets (minimal) base box
    void setBaseBBox(const ccBBox& box);

	//! Forces the 'keep square' mode
	void forceKeepSquare(bool state);

	//! Returns whether 'keep square' mode is enabled or not
	bool keepSquare() const;

	//! Sets 2D mode (Z line will be hidden)
	void set2DMode(bool state);

public slots:

	//overloaded from QDialog
	virtual int	exec();

protected slots:

	void squareModeActivated(bool);
	void reset();
	void cancel();

	void updateXWidth(double);
	void updateYWidth(double);
	void updateZWidth(double);

	//! Updates current box based on the dialog state
	void updateCurrentBBox(double dummy = 0.0);
	//! Reflects changes on bbox
	void reflectChanges(int dummy = 0);

protected:

	//! Checks if currentBox includes baseBox
	void checkBaseInclusion();

	//! Minimal box (invalid if none)
	ccBBox m_baseBBox;

	//! Current box
	ccBBox m_currentBBox;

	//! Box state at dialog start
	ccBBox m_initBBox;

};

#endif //CC_BOUNDING_BOX_EDITOR_DLG_HEADER