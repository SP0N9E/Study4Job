# ShaderLab相关

[TOC]

## 1.Blend命令

|                         语义                          |                             描述                             |
| :---------------------------------------------------: | :----------------------------------------------------------: |
|                       Blend Off                       |                           关闭混合                           |
|               Blend SrcFactor DstFactor               | 开启混合，并设置混合因子。源颜色(该片元产生的颜色)会乘以SrcFactor，而目标颜色(已经存在于颜色缓存的颜色)会乘以DstFactor，然后把两者相加后再存入颜色缓冲中 |
| Blend SrcFactor DstFactor,<br />SrcFactorA DstFactorA |       和上面几乎一样，只是使用不同的因子来混合透明通道       |
|                BlendOp BlendOperation                 | 并非是把源颜色和目标颜色简单相加后混合，而是使用BlendOperation对它们进行其他操作。 |

使用例子

```
Pass
{
	Tags {"LightMode"="ForwardBase"}
	ZWrite Off
	Blend SrcAlpha OneMinusSrcAlpha
}
```



## 2.SubShader使用的标签

`"IgnoreProject"="True"`: 意味着这个Shader不会受到投影器的影响

`“RenderType”="Transparent"`: 可以让Unity把这个Shader归入到提前定义的组



## 3.Cull指令

默认情况下渲染引擎剔除了物体背面(相对于摄像机方向)的渲染图元，而只渲染了物体的正面。如果我们想要得到双面渲染的效果，可以使用Cull指令来控制需要剔除哪个面的渲染图元。

Cull的指令语法如下：

```
Cull Back | Front | Off
```

如果设置为Back，那么哪些背对这摄像机的渲染图元不会被渲染，这也是默认状态下的选项。如果设置为Front，那么那些朝向摄像机的渲染图元不会被渲染。如果设置为Off，那么就关闭了剔除。

















