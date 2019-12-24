<footer class="footer mt-auto py-3">
    <div class="container">
        <span class="text-center">
            <p class="text-center">Kelompok 5 &#169; 2019</p>
        </span>
    </div>
</footer>
</body>
<script src="<?= base_url(); ?>assets/js/jquery/dist/jquery.slim.min.js"></script>
<script src="<?= base_url(); ?>assets/js/popper.js/dist/popper.min.js"></script>
<script src="<?= base_url(); ?>assets/js/bootstrap.min.js"></script>
<script src="<?= base_url(); ?>assets/fontawesome/js/all.js"></script>

<script src="<?= base_url(); ?>assets/js/graph/highcharts.js"></script>
<script src="<?= base_url(); ?>assets/js/graph/exporting.js"></script>
<script src="<?= base_url(); ?>assets/js/graph/export-data.js"></script>
<!-- <script src="<?= base_url(); ?>assets/js/graph/graph.js"></script> -->
<script type="text/javascript">
    jQuery(function() {
        Highcharts.chart('container', {
            chart: {
                type: 'line'
            },
            title: {
                text: 'Suhu dan Kelembapan'
            },
            subtitle: {
                text: 'Source: DHT 11 Sensors'
            },
            xAxis: {
                categories: <?php echo json_encode($waktu); ?>
            },
            yAxis: {
                title: {
                    text: 'Temperature (°C)'
                }
            },
            plotOptions: {
                line: {
                    dataLabels: {
                        enabled: true
                    },
                    enableMouseTracking: false
                }
            },
            series: [{
                name: 'Tokyo',
                data: <?php echo json_encode($data); ?>
            }, {
                name: 'London',
                data: <?php echo json_encode($suhu); ?>
            }]
        });

    });
</script>


</html>