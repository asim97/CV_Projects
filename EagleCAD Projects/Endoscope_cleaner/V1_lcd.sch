<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.5.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="display-lcd" urn="urn:adsk.eagle:library:214">
<description>&lt;b&gt;Hitachi, Data Modul, Tuxgraphics - LCD Displays&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="TUXGR_20X2" urn="urn:adsk.eagle:footprint:13122/1" locally_modified="yes" library_version="1" library_locally_modified="yes">
<description>&lt;b&gt;Tuxgraphics LCD display 20x2 characters&lt;/b&gt; reflective, without background light&lt;p&gt;
Source: tuxgr_20x2.pdf</description>
<wire x1="-57.9" y1="18.4" x2="57.9" y2="18.4" width="0.2032" layer="21"/>
<wire x1="57.9" y1="18.4" x2="57.9" y2="-18.4" width="0.2032" layer="21"/>
<wire x1="57.9" y1="-18.4" x2="-57.9" y2="-18.4" width="0.2032" layer="21"/>
<wire x1="-57.9" y1="-18.4" x2="-57.9" y2="18.4" width="0.2032" layer="21"/>
<wire x1="-40.4" y1="9.15" x2="42.4" y2="9.15" width="0.2032" layer="21"/>
<wire x1="42.4" y1="9.15" x2="42.4" y2="-9.15" width="0.2032" layer="21"/>
<wire x1="42.4" y1="-9.15" x2="-40.4" y2="-9.15" width="0.2032" layer="21"/>
<wire x1="-40.4" y1="-9.15" x2="-40.4" y2="9.15" width="0.2032" layer="21"/>
<wire x1="-44.5" y1="15.5" x2="46.5" y2="15.5" width="0.2032" layer="21"/>
<wire x1="46.5" y1="15.5" x2="46.5" y2="-15.5" width="0.2032" layer="21"/>
<wire x1="46.5" y1="-15.5" x2="-44.5" y2="-15.5" width="0.2032" layer="21"/>
<wire x1="-44.5" y1="-15.5" x2="-44.5" y2="15.5" width="0.2032" layer="21"/>
<pad name="1" x="-52.73" y="-8.89" drill="1" diameter="1.6764"/>
<pad name="2" x="-55.27" y="-8.89" drill="1" diameter="1.6764"/>
<pad name="3" x="-52.73" y="-6.35" drill="1" diameter="1.6764"/>
<pad name="4" x="-55.27" y="-6.35" drill="1" diameter="1.6764"/>
<pad name="5" x="-52.73" y="-3.81" drill="1" diameter="1.6764"/>
<pad name="6" x="-55.27" y="-3.81" drill="1" diameter="1.6764"/>
<pad name="7" x="-52.73" y="-1.27" drill="1" diameter="1.6764"/>
<pad name="8" x="-55.27" y="-1.27" drill="1" diameter="1.6764"/>
<pad name="9" x="-52.73" y="1.27" drill="1" diameter="1.6764"/>
<pad name="10" x="-55.27" y="1.27" drill="1" diameter="1.6764"/>
<pad name="11" x="-52.73" y="3.81" drill="1" diameter="1.6764"/>
<pad name="12" x="-55.27" y="3.81" drill="1" diameter="1.6764"/>
<pad name="13" x="-52.73" y="6.35" drill="1" diameter="1.6764"/>
<pad name="14" x="-55.27" y="6.35" drill="1" diameter="1.6764"/>
<pad name="15" x="-52.73" y="8.89" drill="1" diameter="1.6764"/>
<pad name="16" x="-55.27" y="8.89" drill="1" diameter="1.6764"/>
<text x="-53.34" y="-20.32" size="1.27" layer="25">&gt;NAME</text>
<text x="-43.18" y="-20.32" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-35.75" y1="0.2" x2="-32.55" y2="5.75" layer="21"/>
<rectangle x1="-35.75" y1="-5.75" x2="-32.55" y2="-0.2" layer="21"/>
<rectangle x1="-32.05" y1="0.2" x2="-28.85" y2="5.75" layer="21"/>
<rectangle x1="-32.05" y1="-5.75" x2="-28.85" y2="-0.2" layer="21"/>
<rectangle x1="-28.35" y1="0.2" x2="-25.15" y2="5.75" layer="21"/>
<rectangle x1="-28.35" y1="-5.75" x2="-25.15" y2="-0.2" layer="21"/>
<rectangle x1="-24.65" y1="0.2" x2="-21.45" y2="5.75" layer="21"/>
<rectangle x1="-24.65" y1="-5.75" x2="-21.45" y2="-0.2" layer="21"/>
<rectangle x1="-20.95" y1="0.2" x2="-17.75" y2="5.75" layer="21"/>
<rectangle x1="-20.95" y1="-5.75" x2="-17.75" y2="-0.2" layer="21"/>
<rectangle x1="-17.25" y1="0.2" x2="-14.05" y2="5.75" layer="21"/>
<rectangle x1="-17.25" y1="-5.75" x2="-14.05" y2="-0.2" layer="21"/>
<rectangle x1="-13.55" y1="0.2" x2="-10.35" y2="5.75" layer="21"/>
<rectangle x1="-13.55" y1="-5.75" x2="-10.35" y2="-0.2" layer="21"/>
<rectangle x1="-9.85" y1="0.2" x2="-6.65" y2="5.75" layer="21"/>
<rectangle x1="-9.85" y1="-5.75" x2="-6.65" y2="-0.2" layer="21"/>
<rectangle x1="-6.15" y1="0.2" x2="-2.95" y2="5.75" layer="21"/>
<rectangle x1="-6.15" y1="-5.75" x2="-2.95" y2="-0.2" layer="21"/>
<rectangle x1="-2.45" y1="0.2" x2="0.75" y2="5.75" layer="21"/>
<rectangle x1="-2.45" y1="-5.75" x2="0.75" y2="-0.2" layer="21"/>
<rectangle x1="1.25" y1="0.2" x2="4.45" y2="5.75" layer="21"/>
<rectangle x1="1.25" y1="-5.75" x2="4.45" y2="-0.2" layer="21"/>
<rectangle x1="4.95" y1="0.2" x2="8.15" y2="5.75" layer="21"/>
<rectangle x1="4.95" y1="-5.75" x2="8.15" y2="-0.2" layer="21"/>
<rectangle x1="8.65" y1="0.2" x2="11.85" y2="5.75" layer="21"/>
<rectangle x1="8.65" y1="-5.75" x2="11.85" y2="-0.2" layer="21"/>
<rectangle x1="12.35" y1="0.2" x2="15.55" y2="5.75" layer="21"/>
<rectangle x1="12.35" y1="-5.75" x2="15.55" y2="-0.2" layer="21"/>
<rectangle x1="16.05" y1="0.2" x2="19.25" y2="5.75" layer="21"/>
<rectangle x1="16.05" y1="-5.75" x2="19.25" y2="-0.2" layer="21"/>
<rectangle x1="19.75" y1="0.2" x2="22.95" y2="5.75" layer="21"/>
<rectangle x1="19.75" y1="-5.75" x2="22.95" y2="-0.2" layer="21"/>
<rectangle x1="23.45" y1="0.2" x2="26.65" y2="5.75" layer="21"/>
<rectangle x1="23.45" y1="-5.75" x2="26.65" y2="-0.2" layer="21"/>
<rectangle x1="27.15" y1="0.2" x2="30.35" y2="5.75" layer="21"/>
<rectangle x1="27.15" y1="-5.75" x2="30.35" y2="-0.2" layer="21"/>
<rectangle x1="30.85" y1="0.2" x2="34.05" y2="5.75" layer="21"/>
<rectangle x1="30.85" y1="-5.75" x2="34.05" y2="-0.2" layer="21"/>
<rectangle x1="34.55" y1="0.2" x2="37.75" y2="5.75" layer="21"/>
<rectangle x1="34.55" y1="-5.75" x2="37.75" y2="-0.2" layer="21"/>
<hole x="-54" y="-14.5" drill="3.5"/>
<hole x="54" y="-14.5" drill="3.5"/>
<hole x="-54" y="14.5" drill="3.5"/>
<hole x="54" y="14.5" drill="3.5"/>
</package>
</packages>
<packages3d>
<package3d name="TUXGR_20X2" urn="urn:adsk.eagle:package:13138/1" type="box" library_version="1">
<description>Tuxgraphics LCD display 20x2 characters reflective, without background light
Source: tuxgr_20x2.pdf</description>
</package3d>
</packages3d>
<symbols>
<symbol name="TUXGR_20X2" urn="urn:adsk.eagle:symbol:13121/1" library_version="1">
<wire x1="-26.67" y1="-7.62" x2="26.67" y2="-7.62" width="0.2032" layer="94"/>
<wire x1="26.67" y1="-7.62" x2="26.67" y2="12.7" width="0.2032" layer="94"/>
<wire x1="26.67" y1="12.7" x2="-26.67" y2="12.7" width="0.2032" layer="94"/>
<wire x1="-26.67" y1="12.7" x2="-26.67" y2="-7.62" width="0.2032" layer="94"/>
<text x="-17.78" y="10.668" size="1.524" layer="94">LCD DISPLAY 20x2</text>
<text x="-25.4" y="13.97" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="13.97" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-25.4" y1="6.604" x2="-23.114" y2="10.16" layer="94"/>
<rectangle x1="-25.4" y1="2.54" x2="-23.114" y2="6.096" layer="94"/>
<rectangle x1="-22.86" y1="6.604" x2="-20.574" y2="10.16" layer="94"/>
<rectangle x1="-22.86" y1="2.54" x2="-20.574" y2="6.096" layer="94"/>
<rectangle x1="-20.32" y1="6.604" x2="-18.034" y2="10.16" layer="94"/>
<rectangle x1="-20.32" y1="2.54" x2="-18.034" y2="6.096" layer="94"/>
<rectangle x1="-17.78" y1="6.604" x2="-15.494" y2="10.16" layer="94"/>
<rectangle x1="-17.78" y1="2.54" x2="-15.494" y2="6.096" layer="94"/>
<rectangle x1="-15.24" y1="6.604" x2="-12.954" y2="10.16" layer="94"/>
<rectangle x1="-15.24" y1="2.54" x2="-12.954" y2="6.096" layer="94"/>
<rectangle x1="-12.7" y1="6.604" x2="-10.414" y2="10.16" layer="94"/>
<rectangle x1="-12.7" y1="2.54" x2="-10.414" y2="6.096" layer="94"/>
<rectangle x1="-10.16" y1="6.604" x2="-7.874" y2="10.16" layer="94"/>
<rectangle x1="-10.16" y1="2.54" x2="-7.874" y2="6.096" layer="94"/>
<rectangle x1="-7.62" y1="6.604" x2="-5.334" y2="10.16" layer="94"/>
<rectangle x1="-7.62" y1="2.54" x2="-5.334" y2="6.096" layer="94"/>
<rectangle x1="-5.08" y1="6.604" x2="-2.794" y2="10.16" layer="94"/>
<rectangle x1="-5.08" y1="2.54" x2="-2.794" y2="6.096" layer="94"/>
<rectangle x1="-2.54" y1="6.604" x2="-0.254" y2="10.16" layer="94"/>
<rectangle x1="-2.54" y1="2.54" x2="-0.254" y2="6.096" layer="94"/>
<rectangle x1="0" y1="6.604" x2="2.286" y2="10.16" layer="94"/>
<rectangle x1="0" y1="2.54" x2="2.286" y2="6.096" layer="94"/>
<rectangle x1="2.54" y1="6.604" x2="4.826" y2="10.16" layer="94"/>
<rectangle x1="2.54" y1="2.54" x2="4.826" y2="6.096" layer="94"/>
<rectangle x1="5.08" y1="6.604" x2="7.366" y2="10.16" layer="94"/>
<rectangle x1="5.08" y1="2.54" x2="7.366" y2="6.096" layer="94"/>
<rectangle x1="7.62" y1="6.604" x2="9.906" y2="10.16" layer="94"/>
<rectangle x1="7.62" y1="2.54" x2="9.906" y2="6.096" layer="94"/>
<rectangle x1="10.16" y1="6.604" x2="12.446" y2="10.16" layer="94"/>
<rectangle x1="10.16" y1="2.54" x2="12.446" y2="6.096" layer="94"/>
<rectangle x1="12.7" y1="6.604" x2="14.986" y2="10.16" layer="94"/>
<rectangle x1="12.7" y1="2.54" x2="14.986" y2="6.096" layer="94"/>
<rectangle x1="15.24" y1="6.604" x2="17.526" y2="10.16" layer="94"/>
<rectangle x1="15.24" y1="2.54" x2="17.526" y2="6.096" layer="94"/>
<rectangle x1="17.78" y1="6.604" x2="20.066" y2="10.16" layer="94"/>
<rectangle x1="17.78" y1="2.54" x2="20.066" y2="6.096" layer="94"/>
<rectangle x1="20.32" y1="6.604" x2="22.606" y2="10.16" layer="94"/>
<rectangle x1="20.32" y1="2.54" x2="22.606" y2="6.096" layer="94"/>
<rectangle x1="22.86" y1="6.604" x2="25.146" y2="10.16" layer="94"/>
<rectangle x1="22.86" y1="2.54" x2="25.146" y2="6.096" layer="94"/>
<pin name="GND" x="-22.86" y="-10.16" length="short" direction="pwr" rot="R90"/>
<pin name="VCC" x="-20.32" y="-10.16" length="short" direction="pwr" rot="R90"/>
<pin name="CONTR" x="-17.78" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="RS" x="-15.24" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="R/W" x="-12.7" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="E" x="-10.16" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D0" x="-7.62" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D1" x="-5.08" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D2" x="-2.54" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D3" x="0" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D4" x="2.54" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D5" x="5.08" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D6" x="7.62" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="D7" x="10.16" y="-10.16" length="short" direction="in" rot="R90"/>
<pin name="NC@1" x="12.7" y="-10.16" length="short" direction="nc" rot="R90"/>
<pin name="NC@2" x="15.24" y="-10.16" length="short" direction="nc" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TUXGR_20X2" urn="urn:adsk.eagle:component:13151/1" locally_modified="yes" prefix="DIS" library_version="1" library_locally_modified="yes">
<description>&lt;b&gt;Tuxgraphics LCD display 20x2 characters&lt;/b&gt; reflective, without background light&lt;p&gt;
Source: tuxgr_20x2.pdf</description>
<gates>
<gate name="G$1" symbol="TUXGR_20X2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TUXGR_20X2">
<connects>
<connect gate="G$1" pin="CONTR" pad="3"/>
<connect gate="G$1" pin="D0" pad="7"/>
<connect gate="G$1" pin="D1" pad="8"/>
<connect gate="G$1" pin="D2" pad="9"/>
<connect gate="G$1" pin="D3" pad="10"/>
<connect gate="G$1" pin="D4" pad="11"/>
<connect gate="G$1" pin="D5" pad="12"/>
<connect gate="G$1" pin="D6" pad="13"/>
<connect gate="G$1" pin="D7" pad="14"/>
<connect gate="G$1" pin="E" pad="6"/>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="NC@1" pad="15"/>
<connect gate="G$1" pin="NC@2" pad="16"/>
<connect gate="G$1" pin="R/W" pad="5"/>
<connect gate="G$1" pin="RS" pad="4"/>
<connect gate="G$1" pin="VCC" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:13138/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="DIS1" library="display-lcd" library_urn="urn:adsk.eagle:library:214" deviceset="TUXGR_20X2" device="" package3d_urn="urn:adsk.eagle:package:13138/1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="DIS1" gate="G$1" x="63.5" y="63.5"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
