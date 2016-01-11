# /app/mailers/report_pdf.rb
class ReportPdf < ApplicationMailer
  def send_mail(report_id:)
    @report = Report.find report_id

    GeneratePdfJob.perform_now(report_id: @report.id)
    @report.reload

    attachments["report_#{Date.today.iso8601}.pdf"] = {
      mime_type: 'application/pdf',
      content: open(@report.pdf.expiring_url).read
    }

    mail(
      to: @report.user.email,
      subject: "Weekly PDF Email: #{Date.today.iso8601}",
    )
  end
end