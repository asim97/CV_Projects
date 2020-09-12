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
<library name="connect">
<packages>
<package name="D-09F/90">
<wire x1="15.24" y1="9.525" x2="15.24" y2="9.144" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-3.81" x2="-14.732" y2="-3.81" width="0.127" layer="21"/>
<wire x1="15.24" y1="5.08" x2="15.24" y2="-3.81" width="0.127" layer="21"/>
<wire x1="8.382" y1="5.08" x2="8.382" y2="-3.81" width="0.127" layer="21"/>
<wire x1="8.382" y1="-3.81" x2="9.144" y2="-3.81" width="0.127" layer="21"/>
<wire x1="15.24" y1="5.08" x2="9.144" y2="5.08" width="0.127" layer="21"/>
<wire x1="9.144" y1="5.08" x2="9.144" y2="-3.81" width="0.127" layer="21"/>
<wire x1="9.144" y1="5.08" x2="8.382" y2="5.08" width="0.127" layer="21"/>
<wire x1="-8.382" y1="5.08" x2="-8.382" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-8.382" y1="-3.81" x2="8.382" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-8.382" y1="5.08" x2="-9.144" y2="5.08" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-3.81" x2="-15.24" y2="5.08" width="0.127" layer="21"/>
<wire x1="-15.24" y1="5.08" x2="-15.24" y2="7.239" width="0.127" layer="21"/>
<wire x1="-9.144" y1="5.08" x2="-9.144" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-9.144" y1="5.08" x2="-15.24" y2="5.08" width="0.127" layer="21"/>
<wire x1="-9.144" y1="-3.81" x2="-8.382" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-15.24" y1="9.144" x2="15.24" y2="9.144" width="0.127" layer="21"/>
<wire x1="15.24" y1="9.144" x2="15.24" y2="7.239" width="0.127" layer="21"/>
<wire x1="-15.24" y1="9.144" x2="-15.24" y2="9.525" width="0.127" layer="21"/>
<wire x1="-15.24" y1="7.239" x2="15.24" y2="7.239" width="0.127" layer="21"/>
<wire x1="-15.24" y1="7.239" x2="-15.24" y2="9.144" width="0.127" layer="21"/>
<wire x1="15.24" y1="7.239" x2="15.24" y2="5.08" width="0.127" layer="21"/>
<wire x1="15.24" y1="9.525" x2="8.763" y2="9.525" width="0.127" layer="21"/>
<wire x1="8.763" y1="9.525" x2="8.255" y2="10.033" width="0.127" layer="21"/>
<wire x1="8.763" y1="9.525" x2="-8.763" y2="9.525" width="0.127" layer="21"/>
<wire x1="8.255" y1="10.033" x2="8.255" y2="15.494" width="0.127" layer="21"/>
<wire x1="-8.255" y1="15.494" x2="-8.255" y2="10.033" width="0.127" layer="21"/>
<wire x1="-8.255" y1="10.033" x2="-8.763" y2="9.525" width="0.127" layer="21"/>
<wire x1="-8.763" y1="9.525" x2="-15.24" y2="9.525" width="0.127" layer="21"/>
<wire x1="7.747" y1="15.748" x2="7.747" y2="10.033" width="0.127" layer="21"/>
<wire x1="9.144" y1="-3.81" x2="10.16" y2="-3.81" width="0.127" layer="21"/>
<wire x1="10.16" y1="1.27" x2="14.732" y2="1.27" width="0.127" layer="21" curve="-180"/>
<wire x1="14.732" y1="-3.81" x2="14.732" y2="1.27" width="0.127" layer="21"/>
<wire x1="14.732" y1="-3.81" x2="15.24" y2="-3.81" width="0.127" layer="21"/>
<wire x1="10.16" y1="-3.81" x2="10.16" y2="1.27" width="0.127" layer="21"/>
<wire x1="10.16" y1="-3.81" x2="14.732" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-14.732" y1="1.27" x2="-10.16" y2="1.27" width="0.127" layer="21" curve="-180"/>
<wire x1="-10.16" y1="-3.81" x2="-10.16" y2="1.27" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-3.81" x2="-9.144" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-14.732" y1="-3.81" x2="-14.732" y2="1.27" width="0.127" layer="21"/>
<wire x1="-14.732" y1="-3.81" x2="-10.16" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-7.747" y1="15.748" x2="-7.747" y2="10.033" width="0.127" layer="21"/>
<wire x1="7.493" y1="16.002" x2="7.747" y2="15.748" width="0.127" layer="21" curve="-90"/>
<wire x1="-7.747" y1="15.748" x2="-7.493" y2="16.002" width="0.127" layer="21" curve="-90"/>
<wire x1="7.747" y1="16.002" x2="8.255" y2="15.494" width="0.127" layer="21" curve="-90"/>
<wire x1="-8.255" y1="15.494" x2="-7.747" y2="16.002" width="0.127" layer="21" curve="-90"/>
<wire x1="-7.747" y1="16.002" x2="7.747" y2="16.002" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-4.445" x2="-6.985" y2="-5.715" width="0.508" layer="21"/>
<wire x1="-6.985" y1="-5.715" x2="-4.445" y2="-5.715" width="0.508" layer="21"/>
<wire x1="-4.445" y1="-5.715" x2="-5.715" y2="-4.445" width="0.508" layer="21"/>
<wire x1="-6.35" y1="-5.207" x2="-5.08" y2="-5.207" width="0.508" layer="21"/>
<wire x1="-5.715" y1="-4.572" x2="-5.715" y2="-4.953" width="0.508" layer="21"/>
<circle x="12.446" y="0" radius="1.8034" width="0.127" layer="21"/>
<circle x="-12.446" y="0" radius="1.8034" width="0.127" layer="21"/>
<pad name="1" x="-5.588" y="-1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="2" x="-2.794" y="-1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="3" x="0" y="-1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="4" x="2.794" y="-1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="5" x="5.588" y="-1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="6" x="-4.191" y="1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="7" x="-1.397" y="1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="8" x="1.397" y="1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<pad name="9" x="4.191" y="1.27" drill="1.016" diameter="1.5748" shape="octagon"/>
<text x="-7.62" y="-1.905" size="1.27" layer="21">1</text>
<text x="6.985" y="-1.905" size="1.27" layer="21">5</text>
<text x="-6.35" y="0.635" size="1.27" layer="21">6</text>
<text x="5.715" y="0.635" size="1.27" layer="21">9</text>
<text x="-1.905" y="10.16" size="1.778" layer="27">&gt;VALUE</text>
<text x="-1.905" y="12.7" size="1.778" layer="25">&gt;NAME</text>
<rectangle x1="-15.24" y1="9.144" x2="15.24" y2="9.525" layer="21"/>
<hole x="12.446" y="0" drill="3.2004"/>
<hole x="-12.446" y="0" drill="3.2004"/>
</package>
</packages>
<symbols>
<symbol name="DB9">
<wire x1="-9.779" y1="5.08" x2="9.779" y2="5.08" width="0.254" layer="94"/>
<wire x1="11.938" y1="-5.08" x2="-12.065" y2="-5.08" width="0.254" layer="94"/>
<wire x1="14.478" y1="-1.524" x2="12.573" y2="3.302" width="0.254" layer="94"/>
<wire x1="10.6426" y1="5.0038" x2="11.0998" y2="4.8514" width="0.254" layer="94"/>
<wire x1="11.0998" y1="4.8514" x2="11.5824" y2="4.5974" width="0.254" layer="94"/>
<wire x1="11.5824" y1="4.5974" x2="11.9634" y2="4.2926" width="0.254" layer="94"/>
<wire x1="11.9634" y1="4.2926" x2="12.2428" y2="3.9116" width="0.254" layer="94"/>
<wire x1="12.2428" y1="3.9116" x2="12.446" y2="3.5814" width="0.254" layer="94"/>
<wire x1="12.446" y1="3.5814" x2="12.573" y2="3.302" width="0.254" layer="94"/>
<wire x1="9.779" y1="5.08" x2="10.2616" y2="5.0546" width="0.254" layer="94"/>
<wire x1="10.2616" y1="5.0546" x2="10.6426" y2="5.0038" width="0.254" layer="94"/>
<wire x1="14.478" y1="-1.524" x2="14.5542" y2="-1.7526" width="0.254" layer="94"/>
<wire x1="14.5542" y1="-1.7526" x2="14.605" y2="-2.032" width="0.254" layer="94"/>
<wire x1="14.605" y1="-2.032" x2="14.6304" y2="-2.286" width="0.254" layer="94"/>
<wire x1="14.6304" y1="-2.286" x2="14.6304" y2="-2.5146" width="0.254" layer="94"/>
<wire x1="14.6304" y1="-2.5146" x2="14.5796" y2="-2.8194" width="0.254" layer="94"/>
<wire x1="14.5796" y1="-2.8194" x2="14.5288" y2="-3.0988" width="0.254" layer="94"/>
<wire x1="14.5288" y1="-3.0988" x2="14.4018" y2="-3.4798" width="0.254" layer="94"/>
<wire x1="14.4018" y1="-3.4798" x2="14.1986" y2="-3.8354" width="0.254" layer="94"/>
<wire x1="14.1986" y1="-3.8354" x2="13.97" y2="-4.1656" width="0.254" layer="94"/>
<wire x1="13.97" y1="-4.1656" x2="13.6398" y2="-4.4958" width="0.254" layer="94"/>
<wire x1="13.6398" y1="-4.4958" x2="13.2334" y2="-4.7498" width="0.254" layer="94"/>
<wire x1="13.2334" y1="-4.7498" x2="12.9032" y2="-4.9022" width="0.254" layer="94"/>
<wire x1="12.9032" y1="-4.9022" x2="12.573" y2="-5.0038" width="0.254" layer="94"/>
<wire x1="12.573" y1="-5.0038" x2="12.2682" y2="-5.0546" width="0.254" layer="94"/>
<wire x1="12.2682" y1="-5.0546" x2="11.938" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-14.478" y1="-1.524" x2="-12.573" y2="3.302" width="0.254" layer="94"/>
<wire x1="-10.6426" y1="5.0038" x2="-11.0998" y2="4.8514" width="0.254" layer="94"/>
<wire x1="-11.0998" y1="4.8514" x2="-11.5824" y2="4.5974" width="0.254" layer="94"/>
<wire x1="-11.5824" y1="4.5974" x2="-11.9634" y2="4.2926" width="0.254" layer="94"/>
<wire x1="-11.9634" y1="4.2926" x2="-12.2428" y2="3.9116" width="0.254" layer="94"/>
<wire x1="-12.2428" y1="3.9116" x2="-12.446" y2="3.5814" width="0.254" layer="94"/>
<wire x1="-12.446" y1="3.5814" x2="-12.573" y2="3.302" width="0.254" layer="94"/>
<wire x1="-10.2616" y1="5.0546" x2="-10.6426" y2="5.0038" width="0.254" layer="94"/>
<wire x1="-14.478" y1="-1.524" x2="-14.5542" y2="-1.7526" width="0.254" layer="94"/>
<wire x1="-14.5542" y1="-1.7526" x2="-14.605" y2="-2.032" width="0.254" layer="94"/>
<wire x1="-14.605" y1="-2.032" x2="-14.6304" y2="-2.286" width="0.254" layer="94"/>
<wire x1="-14.6304" y1="-2.286" x2="-14.6304" y2="-2.5146" width="0.254" layer="94"/>
<wire x1="-14.6304" y1="-2.5146" x2="-14.5796" y2="-2.8194" width="0.254" layer="94"/>
<wire x1="-14.5796" y1="-2.8194" x2="-14.5288" y2="-3.0988" width="0.254" layer="94"/>
<wire x1="-14.5288" y1="-3.0988" x2="-14.4018" y2="-3.4798" width="0.254" layer="94"/>
<wire x1="-14.4018" y1="-3.4798" x2="-14.1986" y2="-3.8354" width="0.254" layer="94"/>
<wire x1="-14.1986" y1="-3.8354" x2="-13.97" y2="-4.1656" width="0.254" layer="94"/>
<wire x1="-13.97" y1="-4.1656" x2="-13.6398" y2="-4.4958" width="0.254" layer="94"/>
<wire x1="-13.6398" y1="-4.4958" x2="-13.2334" y2="-4.7498" width="0.254" layer="94"/>
<wire x1="-13.2334" y1="-4.7498" x2="-12.9032" y2="-4.9022" width="0.254" layer="94"/>
<wire x1="-12.9032" y1="-4.9022" x2="-12.573" y2="-5.0038" width="0.254" layer="94"/>
<wire x1="-12.573" y1="-5.0038" x2="-12.2682" y2="-5.0546" width="0.254" layer="94"/>
<wire x1="-12.2682" y1="-5.0546" x2="-12.065" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-9.779" y1="5.08" x2="-10.2616" y2="5.0546" width="0.254" layer="94"/>
<circle x="7.62" y="2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="2.54" y="2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="-2.54" y="2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="-7.62" y="2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="-10.16" y="-2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="-5.08" y="-2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="0" y="-2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="5.08" y="-2.54" radius="0.9398" width="0.254" layer="94"/>
<circle x="10.16" y="-2.54" radius="0.9398" width="0.254" layer="94"/>
<text x="-12.7" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="1.905" y="5.715" size="1.778" layer="96">&gt;VALUE</text>
<text x="10.9728" y="-3.6322" size="1.27" layer="94" rot="R180">1</text>
<text x="5.8166" y="-3.6068" size="1.27" layer="94" rot="R180">2</text>
<text x="0.7874" y="-3.6322" size="1.27" layer="94" rot="R180">3</text>
<text x="-4.4196" y="-3.6322" size="1.27" layer="94" rot="R180">4</text>
<text x="-9.3726" y="-3.6068" size="1.27" layer="94" rot="R180">5</text>
<text x="8.255" y="1.27" size="1.27" layer="94" rot="R180">6</text>
<text x="3.175" y="1.27" size="1.27" layer="94" rot="R180">7</text>
<text x="-1.905" y="1.27" size="1.27" layer="94" rot="R180">8</text>
<text x="-6.985" y="1.27" size="1.27" layer="94" rot="R180">9</text>
<pin name="5" x="-10.16" y="-2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="4" x="-5.08" y="-2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="3" x="0" y="-2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="2" x="5.08" y="-2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="1" x="10.16" y="-2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="6" x="7.62" y="2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="7" x="2.54" y="2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="8" x="-2.54" y="2.54" visible="off" length="point" direction="pas" rot="R270"/>
<pin name="9" x="-7.62" y="2.54" visible="off" length="point" direction="pas" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DB9F/90" prefix="CON" uservalue="yes">
<gates>
<gate name="G$1" symbol="DB9" x="0" y="0"/>
</gates>
<devices>
<device name="" package="D-09F/90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-wago-500" urn="urn:adsk.eagle:library:195">
<description>&lt;b&gt;Wago Screw Clamps&lt;/b&gt;&lt;p&gt;
Grid 5.00 mm&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="W237-102" urn="urn:adsk.eagle:footprint:10676/1" library_version="1">
<description>&lt;b&gt;WAGO SCREW CLAMP&lt;/b&gt;</description>
<wire x1="-3.491" y1="-2.286" x2="-1.484" y2="-0.279" width="0.254" layer="51"/>
<wire x1="1.488" y1="-2.261" x2="3.469" y2="-0.254" width="0.254" layer="51"/>
<wire x1="-4.989" y1="-5.461" x2="4.993" y2="-5.461" width="0.1524" layer="21"/>
<wire x1="4.993" y1="3.734" x2="4.993" y2="3.531" width="0.1524" layer="21"/>
<wire x1="4.993" y1="3.734" x2="-4.989" y2="3.734" width="0.1524" layer="21"/>
<wire x1="-4.989" y1="-5.461" x2="-4.989" y2="-3.073" width="0.1524" layer="21"/>
<wire x1="-4.989" y1="-3.073" x2="-3.389" y2="-3.073" width="0.1524" layer="21"/>
<wire x1="-3.389" y1="-3.073" x2="-1.611" y2="-3.073" width="0.1524" layer="51"/>
<wire x1="-1.611" y1="-3.073" x2="1.615" y2="-3.073" width="0.1524" layer="21"/>
<wire x1="3.393" y1="-3.073" x2="4.993" y2="-3.073" width="0.1524" layer="21"/>
<wire x1="-4.989" y1="-3.073" x2="-4.989" y2="3.531" width="0.1524" layer="21"/>
<wire x1="4.993" y1="-3.073" x2="4.993" y2="-5.461" width="0.1524" layer="21"/>
<wire x1="-4.989" y1="3.531" x2="4.993" y2="3.531" width="0.1524" layer="21"/>
<wire x1="-4.989" y1="3.531" x2="-4.989" y2="3.734" width="0.1524" layer="21"/>
<wire x1="4.993" y1="3.531" x2="4.993" y2="-3.073" width="0.1524" layer="21"/>
<wire x1="1.615" y1="-3.073" x2="3.393" y2="-3.073" width="0.1524" layer="51"/>
<circle x="-2.5" y="-1.27" radius="1.4986" width="0.1524" layer="51"/>
<circle x="-2.5" y="2.2098" radius="0.508" width="0.1524" layer="21"/>
<circle x="2.5038" y="-1.27" radius="1.4986" width="0.1524" layer="51"/>
<circle x="2.5038" y="2.2098" radius="0.508" width="0.1524" layer="21"/>
<pad name="1" x="-2.5" y="-1.27" drill="1.1938" shape="long" rot="R90"/>
<pad name="2" x="2.5" y="-1.27" drill="1.1938" shape="long" rot="R90"/>
<text x="-5.04" y="-7.62" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-3.8462" y="-5.0038" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-4.532" y="0.635" size="1.27" layer="21" ratio="10">1</text>
<text x="0.421" y="0.635" size="1.27" layer="21" ratio="10">2</text>
</package>
</packages>
<packages3d>
<package3d name="W237-102" urn="urn:adsk.eagle:package:10688/1" type="box" library_version="1">
<description>WAGO SCREW CLAMP</description>
</package3d>
</packages3d>
<symbols>
<symbol name="KL" urn="urn:adsk.eagle:symbol:10675/1" library_version="1">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="0" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="KL+V" urn="urn:adsk.eagle:symbol:10673/1" library_version="1">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-3.683" size="1.778" layer="96">&gt;VALUE</text>
<text x="0" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="W237-102" urn="urn:adsk.eagle:component:10702/1" prefix="X" uservalue="yes" library_version="1">
<description>&lt;b&gt;WAGO SCREW CLAMP&lt;/b&gt;</description>
<gates>
<gate name="-1" symbol="KL" x="0" y="5.08" addlevel="always"/>
<gate name="-2" symbol="KL+V" x="0" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="W237-102">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:10688/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="237-102" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="70K9898" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="holes">
<description>&lt;b&gt;Mounting Holes and Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2,8">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 2.8 mm with drill center</description>
<wire x1="-1.778" y1="0" x2="0" y2="-1.778" width="2.286" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="1.778" x2="1.778" y2="0" width="2.286" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.635" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="2.921" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="2.54" width="2.032" layer="40"/>
<circle x="0" y="0" radius="2.54" width="2.032" layer="39"/>
<circle x="0" y="0" radius="2.54" width="2.032" layer="41"/>
<circle x="0" y="0" radius="2.54" width="2.032" layer="42"/>
<circle x="0" y="0" radius="2.54" width="2.032" layer="43"/>
<circle x="0" y="0" radius="1.5" width="0.2032" layer="21"/>
<hole x="0" y="0" drill="2.8"/>
</package>
<package name="3,0">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 3.0 mm with drill center</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="39"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="43"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="40"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="41"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="42"/>
<circle x="0" y="0" radius="1.6" width="0.2032" layer="21"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,0</text>
<hole x="0" y="0" drill="3"/>
</package>
<package name="3,3">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 3.3 mm with drill center</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.048" width="2.54" layer="39"/>
<circle x="0" y="0" radius="3.048" width="2.54" layer="40"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="43"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="41"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="42"/>
<circle x="0" y="0" radius="1.75" width="0.2032" layer="21"/>
<hole x="0" y="0" drill="3.3"/>
</package>
<package name="3,6">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 3.6 mm with drill center</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.048" width="2.7686" layer="39"/>
<circle x="0" y="0" radius="3.048" width="2.7686" layer="40"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="43"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="41"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="42"/>
<circle x="0" y="0" radius="1.9" width="0.2032" layer="21"/>
<hole x="0" y="0" drill="3.6"/>
</package>
<package name="4,1">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 4.1 mm with drill center</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="39"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="40"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="41"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="42"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="43"/>
<circle x="0" y="0" radius="2.15" width="0.1524" layer="21"/>
<hole x="0" y="0" drill="4.1"/>
</package>
<package name="4,5">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 4.5 mm with drill center</description>
<wire x1="4.445" y1="0" x2="2.159" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="4.445" x2="0" y2="2.159" width="0.0508" layer="21"/>
<wire x1="-2.159" y1="0" x2="-4.445" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.159" x2="0" y2="-4.445" width="0.0508" layer="21"/>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="39"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="40"/>
<circle x="0" y="0" radius="3.8184" width="2.54" layer="41"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="42"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="43"/>
<circle x="0" y="0" radius="2.35" width="0.1524" layer="21"/>
<text x="-1.27" y="-4.445" size="1.27" layer="48">4,5</text>
<hole x="0" y="0" drill="4.5"/>
</package>
<package name="5,0">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 5.0 mm with drill center</description>
<wire x1="4.445" y1="0" x2="2.159" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="4.445" x2="0" y2="2.159" width="0.0508" layer="21"/>
<wire x1="-2.159" y1="0" x2="-4.445" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.159" x2="0" y2="-4.445" width="0.0508" layer="21"/>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="39"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="40"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="43"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="42"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="41"/>
<circle x="0" y="0" radius="2.6" width="0.1524" layer="21"/>
<text x="-1.27" y="-4.445" size="1.27" layer="48">5,0</text>
<hole x="0" y="0" drill="5"/>
</package>
<package name="3,2">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 3.2 mm with drill center</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="39"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="43"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="40"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="41"/>
<circle x="0" y="0" radius="3.048" width="2.032" layer="42"/>
<circle x="0" y="0" radius="1.7" width="0.2032" layer="21"/>
<hole x="0" y="0" drill="3.2"/>
</package>
<package name="4,3">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 4.3 mm with drill center</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="39"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="40"/>
<circle x="0" y="0" radius="3.8184" width="2.54" layer="41"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="42"/>
<circle x="0" y="0" radius="3.81" width="2.54" layer="43"/>
<circle x="0" y="0" radius="2.25" width="0.1524" layer="21"/>
<hole x="0" y="0" drill="4.3"/>
</package>
<package name="5,5">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; 5.5 mm with drill center</description>
<wire x1="4.445" y1="0" x2="2.159" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="4.445" x2="0" y2="2.159" width="0.0508" layer="21"/>
<wire x1="-2.159" y1="0" x2="-4.445" y2="0" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.159" x2="0" y2="-4.445" width="0.0508" layer="21"/>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="39"/>
<circle x="0" y="0" radius="4.699" width="4.5466" layer="40"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="43"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="42"/>
<circle x="0" y="0" radius="4.826" width="2.54" layer="41"/>
<circle x="0" y="0" radius="2.85" width="0.1524" layer="21"/>
<hole x="0" y="0" drill="5.5"/>
</package>
</packages>
<symbols>
<symbol name="MOUNT-HOLE">
<wire x1="0" y1="1.27" x2="1.27" y2="0" width="1.524" layer="94" curve="-90" cap="flat"/>
<wire x1="-1.27" y1="0" x2="0" y2="-1.27" width="1.524" layer="94" curve="90" cap="flat"/>
<wire x1="-0.508" y1="0" x2="0.508" y2="0" width="0.0508" layer="94"/>
<wire x1="0" y1="0.508" x2="0" y2="-0.508" width="0.0508" layer="94"/>
<circle x="0" y="0" radius="2.032" width="0.0508" layer="94"/>
<circle x="0" y="0" radius="0.508" width="0.0508" layer="94"/>
<text x="2.032" y="0.5842" size="1.778" layer="95">&gt;NAME</text>
<text x="2.032" y="-2.4638" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOUNT-HOLE" prefix="H">
<description>&lt;b&gt;MOUNTING HOLE&lt;/b&gt; with drill center marker</description>
<gates>
<gate name="G$1" symbol="MOUNT-HOLE" x="0" y="0"/>
</gates>
<devices>
<device name="2.8" package="2,8">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.0" package="3,0">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.3" package="3,3">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.6" package="3,6">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.1" package="4,1">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.5" package="4,5">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.0" package="5,0">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.2" package="3,2">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.3" package="4,3">
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.5" package="5,5">
<technologies>
<technology name=""/>
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
<part name="CON1" library="connect" deviceset="DB9F/90" device=""/>
<part name="X1" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X2" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X3" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X4" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X5" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X6" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X7" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="X8" library="con-wago-500" library_urn="urn:adsk.eagle:library:195" deviceset="W237-102" device="" package3d_urn="urn:adsk.eagle:package:10688/1"/>
<part name="H1" library="holes" deviceset="MOUNT-HOLE" device="3.0" value="3 MM"/>
<part name="H2" library="holes" deviceset="MOUNT-HOLE" device="3.0" value="3 MM"/>
<part name="H3" library="holes" deviceset="MOUNT-HOLE" device="3.0" value="3 MM"/>
</parts>
<sheets>
<sheet>
<description>InputBoard</description>
<plain>
</plain>
<instances>
<instance part="CON1" gate="G$1" x="81.28" y="48.26" rot="R90"/>
<instance part="X1" gate="-1" x="17.78" y="66.04"/>
<instance part="X1" gate="-2" x="17.78" y="60.96"/>
<instance part="X2" gate="-1" x="17.78" y="50.8"/>
<instance part="X2" gate="-2" x="17.78" y="45.72"/>
<instance part="X3" gate="-1" x="17.78" y="35.56"/>
<instance part="X3" gate="-2" x="17.78" y="30.48"/>
<instance part="X4" gate="-1" x="17.78" y="20.32"/>
<instance part="X4" gate="-2" x="17.78" y="15.24"/>
<instance part="X5" gate="-1" x="40.64" y="66.04"/>
<instance part="X5" gate="-2" x="40.64" y="60.96"/>
<instance part="X6" gate="-1" x="40.64" y="50.8"/>
<instance part="X6" gate="-2" x="40.64" y="45.72"/>
<instance part="X7" gate="-1" x="40.64" y="35.56"/>
<instance part="X7" gate="-2" x="40.64" y="30.48"/>
<instance part="X8" gate="-1" x="40.64" y="20.32"/>
<instance part="X8" gate="-2" x="40.64" y="15.24"/>
<instance part="H1" gate="G$1" x="66.04" y="20.32"/>
<instance part="H2" gate="G$1" x="78.74" y="20.32"/>
<instance part="H3" gate="G$1" x="91.44" y="20.32"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="9"/>
<wire x1="78.74" y1="40.64" x2="66.04" y2="40.64" width="0.1524" layer="91"/>
<label x="66.04" y="40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-2" pin="KL"/>
<wire x1="22.86" y1="60.96" x2="30.48" y2="60.96" width="0.1524" layer="91"/>
<label x="25.4" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X2" gate="-2" pin="KL"/>
<wire x1="22.86" y1="45.72" x2="30.48" y2="45.72" width="0.1524" layer="91"/>
<label x="25.4" y="45.72" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X3" gate="-2" pin="KL"/>
<wire x1="22.86" y1="30.48" x2="30.48" y2="30.48" width="0.1524" layer="91"/>
<label x="25.4" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X4" gate="-2" pin="KL"/>
<wire x1="22.86" y1="15.24" x2="30.48" y2="15.24" width="0.1524" layer="91"/>
<label x="25.4" y="15.24" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X5" gate="-2" pin="KL"/>
<wire x1="45.72" y1="60.96" x2="53.34" y2="60.96" width="0.1524" layer="91"/>
<label x="48.26" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X6" gate="-2" pin="KL"/>
<wire x1="45.72" y1="45.72" x2="53.34" y2="45.72" width="0.1524" layer="91"/>
<label x="48.26" y="45.72" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X7" gate="-2" pin="KL"/>
<wire x1="45.72" y1="30.48" x2="53.34" y2="30.48" width="0.1524" layer="91"/>
<label x="48.26" y="30.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X8" gate="-2" pin="KL"/>
<wire x1="45.72" y1="15.24" x2="53.34" y2="15.24" width="0.1524" layer="91"/>
<label x="48.26" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN0" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="1"/>
<wire x1="83.82" y1="58.42" x2="96.52" y2="58.42" width="0.1524" layer="91"/>
<label x="88.9" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-1" pin="KL"/>
<wire x1="22.86" y1="66.04" x2="30.48" y2="66.04" width="0.1524" layer="91"/>
<label x="25.4" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN2" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="3"/>
<wire x1="83.82" y1="48.26" x2="96.52" y2="48.26" width="0.1524" layer="91"/>
<label x="88.9" y="48.26" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X3" gate="-1" pin="KL"/>
<wire x1="22.86" y1="35.56" x2="30.48" y2="35.56" width="0.1524" layer="91"/>
<label x="25.4" y="35.56" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN1" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="2"/>
<wire x1="83.82" y1="53.34" x2="96.52" y2="53.34" width="0.1524" layer="91"/>
<label x="88.9" y="53.34" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X2" gate="-1" pin="KL"/>
<wire x1="22.86" y1="50.8" x2="30.48" y2="50.8" width="0.1524" layer="91"/>
<label x="25.4" y="50.8" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN3" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="4"/>
<wire x1="83.82" y1="43.18" x2="96.52" y2="43.18" width="0.1524" layer="91"/>
<label x="88.9" y="43.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X4" gate="-1" pin="KL"/>
<wire x1="22.86" y1="20.32" x2="30.48" y2="20.32" width="0.1524" layer="91"/>
<label x="25.4" y="20.32" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN4" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="5"/>
<wire x1="83.82" y1="38.1" x2="96.52" y2="38.1" width="0.1524" layer="91"/>
<label x="88.9" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X5" gate="-1" pin="KL"/>
<wire x1="45.72" y1="66.04" x2="53.34" y2="66.04" width="0.1524" layer="91"/>
<label x="48.26" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN5" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="6"/>
<wire x1="78.74" y1="55.88" x2="66.04" y2="55.88" width="0.1524" layer="91"/>
<label x="66.04" y="55.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X6" gate="-1" pin="KL"/>
<wire x1="45.72" y1="50.8" x2="53.34" y2="50.8" width="0.1524" layer="91"/>
<label x="48.26" y="50.8" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN6" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="7"/>
<wire x1="78.74" y1="50.8" x2="66.04" y2="50.8" width="0.1524" layer="91"/>
<label x="66.04" y="50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X7" gate="-1" pin="KL"/>
<wire x1="45.72" y1="35.56" x2="53.34" y2="35.56" width="0.1524" layer="91"/>
<label x="48.26" y="35.56" size="1.778" layer="95"/>
</segment>
</net>
<net name="CAN7" class="0">
<segment>
<pinref part="CON1" gate="G$1" pin="8"/>
<wire x1="78.74" y1="45.72" x2="66.04" y2="45.72" width="0.1524" layer="91"/>
<label x="66.04" y="45.72" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X8" gate="-1" pin="KL"/>
<wire x1="45.72" y1="20.32" x2="53.34" y2="20.32" width="0.1524" layer="91"/>
<label x="48.26" y="20.32" size="1.778" layer="95"/>
</segment>
</net>
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
