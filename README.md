#Fractol - a 42\_school's project

A graphical application for drawing fractals

<img align="center" src="http://i.imgur.com/ZsUfV8N.png" width="100%" />

##Install & launch
```bash
git clone https://github.com/ThomasBreart/Fractol.git ~/Fractol
cd ~/Fractol && make && ./fractol --OpenCL Mandelbrot
```

##Usage
```bash
usage: ./fractol [--OpenCL] Mandelbrot | Julia | Burning\_ship | Julia\_ship | Multibrot | Manowar | Barnsleyj | Spider
```

##Main features
<img align="right" src="http://i.imgur.com/zuWTuWk.png" width="18%" />
- 8 types of fractals available
- Zoom and unzoom
- Keyboard controls
- Edit the shape of the fractal with the position of the mouse
- Navigate between the fractals
- Design with OpenCL

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the display gradient (aka change color)</td>
<td valign="top" align="center"><kbd>&nbsp;7&nbsp;</kbd> or <kbd>&nbsp;8&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable or disable the mouse controls</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the numbre of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change fractal type</td>
<td valign="top" align="center"><kbd>&nbsp;page up&nbsp;</kdb> or <kbd>&nbsp;page down&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Show the hud / menu</td>
<td valign="top" align="center"><kbd>&nbsp;F16&nbsp;</kdb></td>
</tr>
</tbody>
</table>

note: keys are part of the numpad
## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Zoom and center the fractal with the cursor position</td>
<td valign="top" align="center"><kbd>&nbsp;left button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Unzoom and center the fractal with the cursor position</td>
<td valign="top" align="center"><kbd>&nbsp;right button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Zoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Unzoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>


##Examples

<img align="left" src="http://i.imgur.com/zqlGrmo.gif" width="30%" />
<img align="left" src="http://i.imgur.com/jVjzJNM.gif" width="30%" />
<img align="left" src="http://i.imgur.com/z8SicTT.gif" width="30%" />
